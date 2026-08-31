# Sonic Horizons Festival

## Team Members
- Nare Maela (24607917)
- Giselle Mpye (Student Number)
- Shepherd Nzimande (25066120)

## Event Concept
Sonic Horizons Festival is a large outdoor music festival consisting of performance areas, food vendors, and operational support services. The system uses the Composite and Observer design patterns to coordinate festival activities.

## Architecture Overview

### Composite Pattern
- FestivalComponent
- FestivalGroup
- FestivalUnit

### Observer Pattern
- FestivalSubject
- FestivalObserver
- FestivalControl

## Build Instructions

```bash
make
```

## Run Instructions

```bash
./eventflow
```

## Doxygen

```bash
doxygen Doxyfile
```