#include <iostream>
#include "FestivalComponent.h"
#include "FestivalObserver.h"


/**
 * @brief Main entry point for the Sonic Horizons Festival simulation.
 * 
 * Demonstrates:
 * - Composite pattern: Building festival hierarchy
 * - Observer pattern: Cascading notifications
 * - Task 4: Event rules, runtime reorganisation, condition-based decisions
 * - Original features: VIPLounge, MerchandiseStand, ShuttleService
 */
int main() {
    std::cout << "=============================================" << std::endl;
    std::cout << "     SONIC HORIZONS FESTIVAL SIMULATION     " << std::endl;
    std::cout << "=============================================" << std::endl;
    
    // ============================================================
    // 1. BUILD THE COMPOSITE TREE (Task 2)
    // ============================================================
    std::cout << "\n--- BUILDING FESTIVAL STRUCTURE ---" << std::endl;
    
    // Create root
    FestivalGroup* root = new FestivalGroup("SonicHorizonsFestival", 10000);
    
    // Create zones
    FestivalGroup* performanceZone = new FestivalGroup("PerformanceZone", 5000);
    FestivalGroup* mainStageArea = new FestivalGroup("MainStageArea", 3000);
    FestivalGroup* electronicStageArea = new FestivalGroup("ElectronicStageArea", 2000);
    FestivalGroup* foodCourt = new FestivalGroup("FoodCourt", 500);
    FestivalGroup* operationsZone = new FestivalGroup("OperationsZone", 200);
    FestivalGroup* vipArea = new FestivalGroup("VIPArea", 100);
    
    // Create leaves
    MainStage* mainStage = new MainStage("The Midnight Echoes", 3000);
    BackStage* backStage = new BackStage(15, 100);
    DJStage* djStage = new DJStage("DJ Nova", 1500);
    DanceFloor* danceFloor = new DanceFloor(500);
    BurgerVendor* burgerVendor = new BurgerVendor(200, 50);
    BeverageVendor* beverageVendor = new BeverageVendor(500, 100);
    SecurityPost* securityPost = new SecurityPost(3, 50);
    FirstAidTent* firstAidTent = new FirstAidTent(10, 20);
    
    // Original features (Task 4.4)
    VIPLounge* vipLounge = new VIPLounge(50, 60);
    MerchandiseStand* merchStand = new MerchandiseStand(100, 30);
    ShuttleService* shuttleService = new ShuttleService(5, 20);
    
    // Build hierarchy (Composite pattern)
    root->add(performanceZone);
    root->add(foodCourt);
    root->add(operationsZone);
    root->add(vipArea);
    
    performanceZone->add(mainStageArea);
    performanceZone->add(electronicStageArea);
    
    mainStageArea->add(mainStage);
    mainStageArea->add(backStage);
    
    electronicStageArea->add(djStage);
    electronicStageArea->add(danceFloor);
    
    foodCourt->add(burgerVendor);
    foodCourt->add(beverageVendor);
    
    operationsZone->add(securityPost);
    operationsZone->add(firstAidTent);
    
    vipArea->add(vipLounge);
    
    std::cout << "Festival structure built successfully!" << std::endl;
    
    // ============================================================
    // 2. SETUP OBSERVER REGISTRATIONS (Task 3)
    // ============================================================
    std::cout << "\n--- SETTING UP OBSERVER REGISTRATIONS ---" << std::endl;
    
    // Create FestivalControl (top-level Subject)
    FestivalControl control;
    
    // Register top-level groups with control
    control.attach(performanceZone);
    control.attach(foodCourt);
    control.attach(operationsZone);
    control.attach(vipArea);
    
    // Register sub-groups with their parent groups
    performanceZone->attach(mainStageArea);
    performanceZone->attach(electronicStageArea);
    
    // Register leaves with their parent groups
    mainStageArea->attach(mainStage);
    mainStageArea->attach(backStage);
    
    electronicStageArea->attach(djStage);
    electronicStageArea->attach(danceFloor);
    
    foodCourt->attach(burgerVendor);
    foodCourt->attach(beverageVendor);
    
    operationsZone->attach(securityPost);
    operationsZone->attach(firstAidTent);
    
    vipArea->attach(vipLounge);
    
    // Register extra observers (not in tree)
    performanceZone->attach(merchStand);
    performanceZone->attach(shuttleService);
    
    std::cout << "Observer registrations complete!" << std::endl;
    
    // ============================================================
    // 3. OPEN THE FESTIVAL (Task 2 - Composite operations)
    // ============================================================
    std::cout << "\n--- OPENING FESTIVAL ---" << std::endl;
    root->open();
    
    // ============================================================
    // 4. REPORT STATUS (Task 2 - Composite query)
    // ============================================================
    std::cout << "\n--- FESTIVAL STATUS ---" << std::endl;
    root->reportStatus();
    
    std::cout << "\nTotal Festival Capacity: " << root->getCapacity() << std::endl;
    
    // ============================================================
    // 5. CASCADING NOTIFICATION - WEATHER ALERT (Task 3.4)
    // ============================================================
    std::cout << "\n--- ISSUING WEATHER ALERT ---" << std::endl;
    Notice weatherNotice("WEATHER_ALERT", "Severe thunderstorm approaching");
    control.issueNotice(&weatherNotice);
    
    // ============================================================
    // 6. CASCADING NOTIFICATION - CAPACITY ALERT (Task 3.4)
    // ============================================================
    std::cout << "\n--- ISSUING CAPACITY ALERT ---" << std::endl;
    Notice capacityNotice("CAPACITY_ALERT", "Capacity limit reached");
    control.issueNotice(&capacityNotice);
    
    // ============================================================
    // 7. CASCADING NOTIFICATION - SCHEDULE CHANGE (Task 4.1)
    // ============================================================
    std::cout << "\n--- ISSUING SCHEDULE CHANGE ---" << std::endl;
    Notice scheduleNotice("SCHEDULE_CHANGE", "Set times have changed");
    control.issueNotice(&scheduleNotice);
    
    // ============================================================
    // 8. RUNTIME REORGANISATION (Task 4.2)
    // ============================================================
    std::cout << "\n--- RUNTIME REORGANISATION ---" << std::endl;
    std::cout << "Transferring BurgerVendor from FoodCourt to PerformanceZone..." << std::endl;
    
    // Remove from FoodCourt
    FestivalComponent* transferred = foodCourt->remove(burgerVendor);
    if (transferred != nullptr) {
        // Add to PerformanceZone
        performanceZone->add(transferred);
        std::cout << "BurgerVendor successfully transferred to PerformanceZone!" << std::endl;
    } else {
        std::cout << "Transfer failed!" << std::endl;
    }
    
    // Show updated structure
    std::cout << "\nUpdated FoodCourt status:" << std::endl;
    foodCourt->reportStatus();
    std::cout << "\nUpdated PerformanceZone status:" << std::endl;
    performanceZone->reportStatus();
    
    // ============================================================
    // 9. DETACH OBSERVER (Task 3 - registration change)
    // ============================================================
    std::cout << "\n--- DETACHING OBSERVER ---" << std::endl;
    std::cout << "Detaching MerchandiseStand from PerformanceZone..." << std::endl;
    performanceZone->detach(merchStand);
    
    // ============================================================
    // 10. CONDITION-BASED DECISION (Task 4.3)
    // ============================================================
    std::cout << "\n--- CONDITION-BASED DECISION ---" << std::endl;
    
    // Simulate capacity alert on DanceFloor
    DanceFloor* danceFloorPtr = dynamic_cast<DanceFloor*>(danceFloor);
    if (danceFloorPtr != nullptr) {
        // Normally this would be set through gameplay, but we'll simulate
        std::cout << "DanceFloor capacity check:" << std::endl;
        Notice capacityCheck("CAPACITY_ALERT", "Checking capacity");
        danceFloorPtr->update(&capacityCheck);
    }
    
    // ============================================================
    // 11. EVACUATION NOTIFICATION (Task 4.1 - different reactions)
    // ============================================================
    std::cout << "\n--- ISSUING EVACUATION NOTICE ---" << std::endl;
    Notice evacuateNotice("EVACUATE", "Emergency evacuation required");
    control.issueNotice(&evacuateNotice);
    
    // ============================================================
    // 12. SHUTDOWN (Task 8.1 - clean shutdown)
    // ============================================================
    std::cout << "\n--- CLOSING FESTIVAL ---" << std::endl;
    root->close();
    
    std::cout << "\n--- FINAL STATUS ---" << std::endl;
    root->reportStatus();
    
    // ============================================================
    // 13. CLEANUP (Task 2.4 - destruction)
    // ============================================================
    std::cout << "\n--- CLEANUP ---" << std::endl;
    std::cout << "Destroying festival hierarchy..." << std::endl;
    
    // Delete root (which recursively deletes all children)
    delete root;
    
    std::cout << "\n=============================================" << std::endl;
    std::cout << "     FESTIVAL SIMULATION COMPLETE          " << std::endl;
    std::cout << "=============================================" << std::endl;
    
    return 0;
}