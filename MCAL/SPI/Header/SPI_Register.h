/*
 * SPI_Register.h
 *
 *  Created on: Oct 29, 2022
 *      Author: wwwmo
 */

#ifndef MCAL_SPI_HEADER_SPI_REGISTER_H_
#define MCAL_SPI_HEADER_SPI_REGISTER_H_

#define SPI_SPCR      (*(volatile u8*)0x2D)
#define SPI_SPSR      (*(volatile u8*)0x2E)
#define SPI_SPDR      (*(volatile u8*)0x2F)

/****  SPCR  ****/
#define SPI_SPIE        7
#define SPI_SPE         6
#define SPI_DORD        5
#define SPI_MSTR        4
#define SPI_CPOL        3
#define SPI_CPHA        2
#define SPI_SPR1        1
#define SPI_SPR0        0

/****  SPSR  ****/
#define SPI_SPIF        7
#define SPI_WCOL        6
#define SPI_SPI2X       0

/****  SPDR  ****/
#define SPI_MSB        7
#define SPI_LSB        0













#endif /* MCAL_SPI_HEADER_SPI_REGISTER_H_ */
