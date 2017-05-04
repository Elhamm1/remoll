#ifndef __MOLLERDETECTORCONSTRUCTION_HH
#define __MOLLERDETECTORCONSTRUCTION_HH

#include "G4GDMLParser.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4Types.hh"

#include <vector>

class G4Tubs;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4VSensitiveDetector;

class remollGlobalField;

class remollDetectorConstruction : public G4VUserDetectorConstruction
{
  public:

    remollDetectorConstruction();
    virtual ~remollDetectorConstruction();

  public:

    G4VPhysicalVolume* Construct();
    void ConstructSDandField();

    void SetDetectorGeomFile(const G4String& name) { fDetFileName = name; }

  private:

    G4GDMLParser *fGDMLParser;

    //----------------------
    // global magnet section
    //----------------------
    //

    static G4ThreadLocal remollGlobalField* fGlobalField;

    G4String fDetFileName;

    G4VPhysicalVolume*      fWorldVolume;

  public:

    void DumpGeometricalTree(G4VPhysicalVolume* aVolume = 0,
      G4int depth = 0, G4bool surfchk = false);

  private:

    G4int UpdateCopyNo(G4VPhysicalVolume* aVolume, G4int index = 0);

};

#endif//__MOLLERDETECTORCONSTRUCTION_HH
