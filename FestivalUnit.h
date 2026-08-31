#ifndef FESTIVALUNIT_H
#define FESTIVALUNIT_H

#include "FestivalComponent.h"
#include "FestivalObserver.h"

/**
 * @brief Represents an operational unit within the festival.
 *
 * FestivalUnit acts as the Leaf participant in the Composite
 * pattern. Unlike FestivalGroup, a FestivalUnit cannot contain
 * other FestivalComponents.
 */
class FestivalUnit : public FestivalComponent, public FestivalObserver
{
protected:

    /**
     * @brief Current operational status of the unit.
     */
    std::string status;

public:

    /**
     * @brief Creates a festival unit.
     *
     * @param name Name of the unit.
     * @param capacity Maximum capacity of the unit.
     */
    FestivalUnit(const std::string& name, int capacity);

    /**
     * @brief Virtual destructor.
     */
    virtual ~FestivalUnit() = default;

    /**
     * @brief Opens the unit.
     */
    virtual void open() override;

    /**
     * @brief Closes the unit.
     */
    virtual void close() override;

    /**
     * @brief Reports the current status of the unit.
     */
    virtual void reportStatus() const override;

    /**
     * @brief Returns the capacity of the unit.
     *
     * @return Unit capacity.
     */
    virtual int getCapacity() const override;

        /**
     * @brief Called when a notice is received from a subject.
     *
     * Concrete leaves override this to react differently to notices.
     *
     * @param notice The notice received. Must not be nullptr.
     */
    virtual void update(Notice* notice) override;
};

#endif