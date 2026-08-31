#include "FestivalComponent.h"

FestivalComponent::FestivalComponent(std::string name, int capacity)
    : name(name), capacity(capacity), isOpen(false)
{
}

FestivalComponent::~FestivalComponent()
{
}


FestivalUnit::FestivalUnit(const std::string& name, int capacity)
    : FestivalComponent(name, capacity)
{
    status = "Closed";
}

void FestivalUnit::open()
{
    isOpen = true;
    status = "Open";
}

void FestivalUnit::close()
{
    isOpen = false;
    status = "Closed";
}

void FestivalUnit::reportStatus() const
{
    std::cout << name
              << " | Status: "
              << status
              << " | Capacity: "
              << capacity
              << std::endl;
}

int FestivalUnit::getCapacity() const
{
    return capacity;
}

void FestivalUnit::update(Notice* notice) {
    if (notice == nullptr) return;
 
    std::cout << name << " received notice: " << notice->getNotice() << std::endl;
}

MainStage::MainStage(const std::string& performer, int capacity)
    : FestivalUnit("Main Stage", capacity),
      currentPerformer(performer)
{
}

void MainStage::reportStatus() const
{
    std::cout << "Main Stage | Performer: "
              << currentPerformer
              << std::endl;
}

void MainStage::open()
{
    isOpen = true;
    std::cout << "The crowd has began gathering as the Main Stage prepares for today's performances."
              << std::endl;
}

void MainStage::close()
{
    isOpen = false;
    std::cout << "The final performance has finished and the Main Stage has shut down for the day."
              << std::endl;
}

void MainStage::update(Notice* notice) {
    if (notice == nullptr) return;
    
    switch (notice->getNoticeType()) {
        case Notice::WEATHER_ALERT:
            std::cout << "MainStage: Pausing performance due to weather!" << std::endl;
            break;
        case Notice::EVACUATE:
            std::cout << "MainStage: Evacuating crowd immediately!" << std::endl;
            break;
        case Notice::OPEN:
            std::cout << "MainStage: Opening for performances." << std::endl;
            break;
        case Notice::CLOSE:
            std::cout << "MainStage: Closing after final performance." << std::endl;
            break;
        case Notice::SCHEDULE_CHANGE:
            std::cout << "MainStage: Adjusting performance schedule." << std::endl;
            break;
        default:
            std::cout << "MainStage: Received notice." << std::endl;
    }
}

BackStage::BackStage(int crewMembers, int capacity)
    : FestivalUnit("Back Stage", capacity),
      crewMembers(crewMembers)
{
}

void BackStage::reportStatus() const
{
    std::cout << "Back Stage | Crew Members: "
              << crewMembers
              << std::endl;
}

void BackStage::open()
{
    isOpen = true;
    std::cout << "Backstage crew is preparing  the equipment and performers for the day."
              << std::endl;
}

void BackStage::close()
{
    isOpen = false;
    std::cout << "Backstage operations have ended and equipment is being secured."
              << std::endl;
}

void BackStage::update(Notice* notice) {
    if (notice == nullptr) return;
    
    switch (notice->getNoticeType()) {
        case Notice::WEATHER_ALERT:
            std::cout << "BackStage: Securing equipment from weather!" << std::endl;
            break;
        case Notice::EVACUATE:
            std::cout << "BackStage: Assisting performers to safety!" << std::endl;
            break;
        case Notice::SCHEDULE_CHANGE:
            std::cout << "BackStage: Coordinating new schedule with crew." << std::endl;
            break;
        case Notice::OPEN:
            std::cout << "BackStage: Opening for crew preparations." << std::endl;
            break;
        case Notice::CLOSE:
            std::cout << "BackStage: Closing operations." << std::endl;
            break;
        default:
            std::cout << "BackStage: Received notice: " << notice->getNotice() << std::endl;
    }
}

DJStage::DJStage(const std::string& dj, int capacity)
    : FestivalUnit("DJ Stage", capacity),
      currentDJ(dj)
{
}

void DJStage::reportStatus() const
{
    std::cout << "DJ Stage | DJ: "
              << currentDJ
              << std::endl;
}

void DJStage::open()
{
    isOpen = true;
    std::cout << "Music begins filling the venue as the DJ Stage opens."
              << std::endl;
}

void DJStage::close()
{
    isOpen = false;
    std::cout << "The DJ Stage has powered down after its final set."
              << std::endl;
}

void DJStage::update(Notice* notice) {
    if (notice == nullptr) return;
    
    switch (notice->getNoticeType()) {
        case Notice::WEATHER_ALERT:
            std::cout << "DJStage: Moving equipment indoors due to weather!" << std::endl;
            break;
        case Notice::EVACUATE:
            std::cout << "DJStage: Shutting down audio and evacuating!" << std::endl;
            break;
        case Notice::SCHEDULE_CHANGE:
            std::cout << "DJStage: Adjusting DJ set times." << std::endl;
            break;
        case Notice::CAPACITY_ALERT:
            std::cout << "DJStage: Limiting entry to dance floor." << std::endl;
            break;
        case Notice::OPEN:
            std::cout << "DJStage: Opening for electronic music sets." << std::endl;
            break;
        case Notice::CLOSE:
            std::cout << "DJStage: Closing after final set." << std::endl;
            break;
        case Notice::PAUSE:
            std::cout << "DJStage: Pausing music temporarily." << std::endl;
            break;
        case Notice::RESUME:
            std::cout << "DJStage: Resuming music." << std::endl;
            break;
        default:
            std::cout << "DJStage: Received notice: " << notice->getNotice() << std::endl;
    }
}

DanceFloor::DanceFloor(int maxOccupancy)
    : FestivalUnit("Dance Floor", maxOccupancy),
      attendeeCount(0),
      maxOccupancy(maxOccupancy)
{
}

void DanceFloor::reportStatus() const
{
    std::cout << "Dance Floor | Attendees: "
              << attendeeCount
              << "/"
              << maxOccupancy
              << std::endl;
}

void DanceFloor::open()
{
    isOpen = true;
    std::cout << "The Dance Floor is now welcoming the festival attendees."
              << std::endl;
}

void DanceFloor::close()
{
    isOpen = false;
    std::cout << "The Dance Floor has been cleared and closed."
              << std::endl;
}

void DanceFloor::update(Notice* notice) {
    if (notice == nullptr) return;
    
    switch (notice->getNoticeType()) {
        case Notice::CAPACITY_ALERT:
            if (attendeeCount >= maxOccupancy) {
                std::cout << "DanceFloor: FULL - No more attendees allowed!" << std::endl;
            } else {
                std::cout << "DanceFloor: " << attendeeCount << "/" << maxOccupancy 
                          << " - still accepting attendees." << std::endl;
            }
            break;
        case Notice::WEATHER_ALERT:
            std::cout << "DanceFloor: Moving attendees indoors due to weather!" << std::endl;
            break;
        case Notice::EVACUATE:
            std::cout << "DanceFloor: Evacuating all attendees!" << std::endl;
            attendeeCount = 0;
            break;
        case Notice::OPEN:
            std::cout << "DanceFloor: Opening for attendees." << std::endl;
            break;
        case Notice::CLOSE:
            std::cout << "DanceFloor: Closing and clearing area." << std::endl;
            break;
        default:
            std::cout << "DanceFloor: Received notice: " << notice->getNotice() << std::endl;
    }
}

BurgerVendor::BurgerVendor(int stockLevel, int capacity)
    : FestivalUnit("Burger Vendor", capacity),
      stockLevel(stockLevel)
{
}

void BurgerVendor::reportStatus() const
{
    std::cout << "Burger Vendor | Stock: "
              << stockLevel
              << std::endl;
}

void BurgerVendor::open()
{
    isOpen = true;
    std::cout << "The smells from the grill start polluting th aeir as we start the service."
              << std::endl;
}

void BurgerVendor::close()
{
    isOpen = false;
    std::cout << "Burger service has ended and the grills are cooling down."
              << std::endl;
}

BeverageVendor::BeverageVendor(int drinkLevel, int capacity)
    : FestivalUnit("Beverage Vendor", capacity),
      drinkLevel(drinkLevel)
{
}

void BeverageVendor::reportStatus() const
{
    std::cout << "Beverage Vendor | Drinks: "
              << drinkLevel
              << std::endl;
}

void BeverageVendor::open()
{
    isOpen = true;
    std::cout << "Cold drinks are now available to festival attendees."
              << std::endl;
}

void BeverageVendor::close()
{
    isOpen = false;
    std::cout << "The Beverage Vendor has stopped serving for the day."
              << std::endl;
}

void BeverageVendor::update(Notice* notice) {
    if (notice == nullptr) return;
    
    switch (notice->getNoticeType()) {
        case Notice::WEATHER_ALERT:
            std::cout << "BeverageVendor: Protecting drinks from weather!" << std::endl;
            break;
        case Notice::EVACUATE:
            std::cout << "BeverageVendor: Closing immediately for evacuation!" << std::endl;
            break;
        case Notice::CAPACITY_ALERT:
            std::cout << "BeverageVendor: Limiting drink sales during capacity alert." << std::endl;
            break;
        case Notice::OPEN:
            std::cout << "BeverageVendor: Opening for service." << std::endl;
            break;
        case Notice::CLOSE:
            std::cout << "BeverageVendor: Closing for the day." << std::endl;
            break;
        default:
            std::cout << "BeverageVendor: Received notice: " << notice->getNotice() << std::endl;
    }
}

void BurgerVendor::update(Notice* notice) {
    if (notice == nullptr) return;
    
    switch (notice->getNoticeType()) {
        case Notice::WEATHER_ALERT:
            std::cout << "BurgerVendor: Closing grill temporarily due to weather!" << std::endl;
            break;
        case Notice::EVACUATE:
            std::cout << "BurgerVendor: Closing immediately for evacuation!" << std::endl;
            break;
        case Notice::CAPACITY_ALERT:
            std::cout << "BurgerVendor: Limiting queue size." << std::endl;
            break;
        case Notice::OPEN:
            std::cout << "BurgerVendor: Opening for service." << std::endl;
            break;
        case Notice::CLOSE:
            std::cout << "BurgerVendor: Closing for the day." << std::endl;
            break;
        case Notice::PAUSE:
            std::cout << "BurgerVendor: Pausing food service." << std::endl;
            break;
        case Notice::RESUME:
            std::cout << "BurgerVendor: Resuming food service." << std::endl;
            break;
        default:
            std::cout << "BurgerVendor: Received notice: " << notice->getNotice() << std::endl;
    }
}

SecurityPost::SecurityPost(int level, int capacity)
    : FestivalUnit("Security Post", capacity),
      securityLevel(level)
{
}

void SecurityPost::open()
{
    isOpen = true;
    std::cout << "Security teams are now monitoring festival grounds."
              << std::endl;
}

void SecurityPost::close()
{
    isOpen = false;
    std::cout << "Security operations are transitioning to shutdown procedures."
              << std::endl;
}

void SecurityPost::reportStatus() const
{
    std::cout << "Security Post | Security Level: "
              << securityLevel
              << std::endl;
}

void SecurityPost::update(Notice* notice) {
    if (notice == nullptr) return;
    
    switch (notice->getNoticeType()) {
        case Notice::CAPACITY_ALERT:
            std::cout << "SecurityPost: Enforcing capacity limits!" << std::endl;
            break;
        case Notice::WEATHER_ALERT:
            std::cout << "SecurityPost: Monitoring weather situation." << std::endl;
            break;
        case Notice::EVACUATE:
            std::cout << "SecurityPost: Assisting with evacuation!" << std::endl;
            break;
        default:
            std::cout << "SecurityPost: Maintaining security." << std::endl;
    }
}

FirstAidTent::FirstAidTent(int staff, int capacity)
    : FestivalUnit("First Aid Tent", capacity),
      medicalStaffCount(staff)
{
}

void FirstAidTent::reportStatus() const
{
    std::cout << "First Aid Tent | Medical Staff: "
              << medicalStaffCount
              << std::endl;
}

void FirstAidTent::open()
{
    isOpen = true;
    std::cout << "Medical staff are ready to assist festival attendees."
              << std::endl;
}

void FirstAidTent::close()
{
    isOpen = false;
    std::cout << "The First Aid Tent has completed its services for the event."
              << std::endl;
}

void FirstAidTent::update(Notice* notice) {
    if (notice == nullptr) return;
    
    switch (notice->getNoticeType()) {
        case Notice::WEATHER_ALERT:
            std::cout << "FirstAidTent: REMAINING OPEN during weather alert!" << std::endl;
            break;
        case Notice::EVACUATE:
            std::cout << "FirstAidTent: Preparing for casualties!" << std::endl;
            break;
        default:
            std::cout << "FirstAidTent: Maintaining medical services." << std::endl;
    }
}

VIPLounge::VIPLounge(int maxVIPCount, int capacity) : FestivalUnit("VIP Lounge", capacity), vipCount(0), maxVIPCount(maxVIPCount) {}

void VIPLounge::reportStatus() const {
    std::cout << "VIP Lounge | VIPs: "
              << vipCount
              << "/"
              << maxVIPCount
              << " | Status: "
              << status
              << std::endl;
}

void VIPLounge::open() {
    isOpen = true;
    status = "Open";
    std::cout << "VIP Lounge is now open for VIP guests."
              << std::endl;
}

void VIPLounge::close() {
    isOpen = false;
    status = "Closed";
    std::cout << "VIP Lounge has closed for the day."
              << std::endl;
}

void VIPLounge::update(Notice* notice) {
    if (notice == nullptr) return;
    
    switch (notice->getNoticeType()) {
        case Notice::CAPACITY_ALERT:
            if (vipCount >= maxVIPCount) {
                std::cout << "VIPLounge: VIP capacity reached - limiting access!" << std::endl;
            } else {
                std::cout << "VIPLounge: Still accepting VIP guests." << std::endl;
            }
            break;
        case Notice::EVACUATE:
            std::cout << "VIPLounge: Escorting VIPs to safety!" << std::endl;
            break;
        case Notice::WEATHER_ALERT:
            std::cout << "VIPLounge: VIPs remain indoors during weather." << std::endl;
            break;
        default:
            std::cout << "VIPLounge: VIP services active." << std::endl;
    }
}

// ============================================================
// MerchandiseStand Implementation (Original Feature 2)
// ============================================================

MerchandiseStand::MerchandiseStand(int inventoryCount, int capacity) : FestivalUnit("Merchandise Stand", capacity), inventoryCount(inventoryCount) {}

void MerchandiseStand::reportStatus() const {
    std::cout << "Merchandise Stand | Inventory: "
              << inventoryCount
              << " | Status: "
              << status
              << std::endl;
}

void MerchandiseStand::open() {
    isOpen = true;
    status = "Open";
    std::cout << "Merchandise Stand is open for business."
              << std::endl;
}

void MerchandiseStand::close() {
    isOpen = false;
    status = "Closed";
    std::cout << "Merchandise Stand has closed for the day."
              << std::endl;
}

void MerchandiseStand::update(Notice* notice) {
    if (notice == nullptr) return;
    
    switch (notice->getNoticeType()) {
        case Notice::WEATHER_ALERT:
            std::cout << "MerchandiseStand: Covering inventory!" << std::endl;
            break;
        case Notice::EVACUATE:
            std::cout << "MerchandiseStand: Securing inventory and closing!" << std::endl;
            break;
        case Notice::OPEN:
            std::cout << "MerchandiseStand: Opening for sales." << std::endl;
            break;
        case Notice::CLOSE:
            std::cout << "MerchandiseStand: Closing for the day." << std::endl;
            break;
        default:
            std::cout << "MerchandiseStand: Selling merchandise." << std::endl;
    }
}

// ============================================================
// ShuttleService Implementation (Original Feature 3)
// ============================================================

ShuttleService::ShuttleService(int activeShuttles, int capacity): FestivalUnit("Shuttle Service", capacity), activeShuttles(activeShuttles), currentRoute("Main Entrance") {}

void ShuttleService::reportStatus() const {
    std::cout << "Shuttle Service | Active Shuttles: "
              << activeShuttles
              << " | Route: "
              << currentRoute
              << " | Status: "
              << status
              << std::endl;
}

void ShuttleService::open() {
    isOpen = true;
    status = "Open";
    std::cout << "Shuttle service is now operating."
              << std::endl;
}

void ShuttleService::close() {
    isOpen = false;
    status = "Closed";
    std::cout << "Shuttle service has stopped for the day."
              << std::endl;
}

void ShuttleService::update(Notice* notice) {
    if (notice == nullptr) return;
    
    switch (notice->getNoticeType()) {
        case Notice::SCHEDULE_CHANGE:
            currentRoute = "Adjusted Route";
            std::cout << "ShuttleService: Adjusting shuttle routes to "
                      << currentRoute << "!" << std::endl;
            break;
        case Notice::EVACUATE:
            currentRoute = "Evacuation Route";
            std::cout << "ShuttleService: Dispatching emergency shuttles to "
                      << currentRoute << "!" << std::endl;
            break;
        case Notice::CAPACITY_ALERT:
            std::cout << "ShuttleService: Adding extra shuttles for capacity." << std::endl;
            break;
        case Notice::WEATHER_ALERT:
            std::cout << "ShuttleService: Modifying routes for weather safety." << std::endl;
            break;
        case Notice::OPEN:
            std::cout << "ShuttleService: Starting operations." << std::endl;
            break;
        case Notice::CLOSE:
            std::cout << "ShuttleService: Ending operations." << std::endl;
            break;
        default:
            std::cout << "ShuttleService: Operating normally." << std::endl;
    }
}