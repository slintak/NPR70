# NPR70 — New Packet Radio for 70 cm Band

A complete open-source hardware and firmware project for a modern IP packet
radio modem operating on the 70 cm amateur band (420–450 MHz).  Compatible with
the NPR (New Packet Radio)
[protocol by F4HDK](https://hackaday.io/project/164092-npr-new-packet-radio),
but with custom hardware and improvements for easier DIY assembly.

## What is NPR70?

**NPR70** is an open-source implementation of a New Packet Radio (NPR) modem — a
  protocol and hardware design for transmitting IP packets over UHF (70 cm)
  amateur radio, with the following goals:

- High throughput (typically 50–500 kbps gross rate)
- Reliable point-to-multipoint IP networking (TCP/IP, UDP, etc.)
- Fully open hardware and software
- Minimal latency and straightforward configuration

This project is **primarily for amateur radio operators** interested in building
and experimenting with modern digital data networks, Hamnet, telemetry, or
similar applications on the UHF band.

It is a fork/derivative of the [original NPR project by F4HDK]
(https://hackaday.io/project/164092-npr-new-packet-radio), but with new custom
hardware, simplified design, and refactored/cleaned firmware.


## Who is this for?

- Licensed amateur radio operators interested in high-speed IP digital modes
- Hamnet and HSMM enthusiasts
- Anyone interested in open hardware wireless networking on UHF

## Hardware Overview

- **MCU**: STM32 microcontroller (STM32L432KCU, as in original)
- **RF Module**: NiceRF module for 70 cm UHF band  (based on SI4463)
- **Ethernet**: W5500 (SPI, 10/100 Mbps Ethernet controller)
- **Form Factor**: Two layer 69×100 mm PCB
- **Other**: 0402 SMD passives, SMA, Ethernet and USB-C connectors, etc.

The hardware is designed to be compact and affordable, with a focus on
DIY manufacturing and community development. All schematics and layout
files are in the [`pcb/`](pcb/) directory.

## Firmware Details

- Based on **MbedOS 5.6.6** (last version compatible with the original code)
- Derived from the [F4HDK NPR firmware]
  (https://github.com/f4hdk/NewPacketRadio), but refactored and cleaned up for
  different pinout
- Supports all main NPR features (TDMA master/slave, 2GFSK/4GFSK,
  point-to-multipoint IP bridging)
- Compatible with official NPR protocol and other compatible modems

## Key Features

| Feature        | Details                                                     |
|----------------|-------------------------------------------------------------|
| **Protocol**   | NPR (custom IP radio, NOT AX.25; true L3)                   |
| **Topology**   | Point-to-multipoint (master + up to 7 clients), TDMA        |
| **Modulation** | 2GFSK / 4GFSK, up to 500 kbps gross (see protocol docs)     |
| **RF Band**    | 70 cm amateur band (configurable, typically 430–440 MHz)    |
| **Network**    | Full IP stack, transparent bridging, works with DHCP, TCP/IP, UDP, etc. |
| **Range**      | Up to 300 km line-of-sight (with suitable antennas and power) |
| **Hardware**   | STM32 MCU, SI4463 radio, W5500 Ethernet, all open hardware  |
| **License**    | GPL v3.0 (same as original NPR project)                     |

## Repository Structure

- `pcb/` – KiCAD project directory (schematic and PCB layout).
- `src/` – Firmware source code, based on MbedOS (legacy version), derived and
  adapted from the original NPR project.

## Quick Start

1. **Hardware**: Manufacture or assemble the PCB found in `pcb/`. BOM and
   assembly notes are included.
2. **Firmware**:
    - For building the code by youself, you will need Debian based system and
      installed `gcc-arm-none-eabi`.
    - Build firmware by running `make` in the `src/` directory.
    - Firmware binary is in  the `src/BUILD/NPR70.hex` file
    - Flash firmware to the STM32 MCU using an SWD programmer
3. **Configuration**: Adjust radio parameters (frequency, bandwidth,
   master/client mode, IP addresses) as described in the
   [original NPR documentation](https://cdn.hackaday.io/files/1640927020512128/NPR70_introduction_EN_v3.6.pdf)
4. **Connect**: Plug in Ethernet and power, connect antenna, and start experimenting

## Documentation and References

- [Original NPR project by F4HDK](https://hackaday.io/project/164092-npr-new-packet-radio)
- [Official NPR documentation (PDFs, guides, protocol)](https://cdn.hackaday.io/files/1640927020512128/NPR70_introduction_EN_v3.6.pdf)
- [Project homepage and build log (in Czech)](https://uart.cz/2773/the-new-packet-radio/)

## License

This project is released under the **GPL v3.0 license**, same as the original
NPR project by F4HDK. See [LICENSE](LICENSE) for full details.

## Contributing

Contributions are welcome! You can:

- Submit hardware design improvements (new PCB revisions, bugfixes)
- Help with firmware optimization, porting to newer MbedOS versions, or adding
  features
- Share test results, deployment reports, and real-world feedback
- Translate documentation

For major changes, please open an issue first to discuss what you would like to
change.

If you have questions or suggestions, feel free to open an
[issue](https://github.com/slintak/NPR70/issues).
