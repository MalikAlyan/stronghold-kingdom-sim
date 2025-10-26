# stronghold-kingdom-sim
**Stronghold Kingdom — C++ OOP Simulation**

A brutal, console-based multiplayer strategy simulation that forces C++ OOP students to master pointers, inheritance, polymorphism, templates, dynamic memory, exceptions, file I/O, randomized events, and time-based actions.
**
Table of contents**

Project overview

Key features

Gameplay & core mechanics (brief)

Implementation & OOP constraints (requirements you must follow)

Build & run instructions

Project structure (recommended)

Saving / file formats

Testing & validation suggestions

Contributing & license

**1. Project overview**

The Stronghold game is an ultra-challenging, console multiplayer strategy game. Players manage a medieval kingdom and must cope with war, politics, economy, corruption, diplomacy, natural disasters, and real-time decisions. The design intentionally imposes strict OOP constraints so students learn to plan architecture, manage dynamic memory, use templates and polymorphism, handle exceptions, and implement complex interdependent systems.


**2. Key features**

Deep, interdependent systems: population, economy, resources, army, politics, market, banking, corruption.

Hardcore realism: training/building use sleep() (time delays), random events via rand().

Multiplayer text-based communication with alliances, deception, trade negotiations.

Persistent saves & score logging (score.txt, save file for game state).

Strict OOP enforcement: classes for each major system, dynamic allocation, templates, exceptions, file I/O.
**
3. Gameplay & core mechanics **

Players manage population and social classes (peasants, merchants, nobility, military). Population influences tax revenue, army recruitment, and stability. Armies require training time and resources; unpaid soldiers desert or riot. Kings are elected with faction influence; corruption, bribery, or assassination can destabilize governance. The economy is dynamic — taxes, inflation, market crashes, loans, and trade sanctions affect your kingdom. Random events (plague, drought, revolts, assassinations) force adaptation.

**4. Implementation & OOP constraints**

All of the following are required by project design:

Three-file structure (minimum):

*.h — class definitions and prototypes

*.cpp — implementations

main.cpp — game flow / user I/O

Modular classes: Each major system must be a class: Kingdom, Army, Bank, Market, Map, Resources, Politics, etc. Provide clear responsibilities per class.

**Inheritance & polymorphism:**

Leader (base) → King, Commander, GuildLeader (derived).

Virtual functions for behaviors (e.g., virtual void enactPolicy()).

Pointers & dynamic memory: All objects are dynamically allocated (new) and properly deallocated (delete). Use smart pointers where sensible (unique_ptr, shared_ptr) and document ownership semantics.

Exceptions: Use try/catch for invalid inputs, file I/O errors, and illegal game actions. Create custom exception types where helpful (e.g., InvalidActionException).

Templates: Use template classes for generalized containers (e.g., template<typename T> class Inventory or Resource<T>).

File handling: Scores and resource logs saved to score.txt. Game state saved/loaded from a separate file format (binary or text).

Time & randomness: Use sleep() to simulate time passing for training/building and rand()/srand() for random events.
