/*!
 * *******************************************************************************
 * @file bitfield.h
 * @author J. Camilo Gomez
 * @version 1.0.3
 * @date Feb 5 , 2020
 * @brief A bit-field manipulation library.
 *********************************************************************************/

#ifndef BITFIELD_H
#define BITFIELD_H

#ifdef __cplusplus
extern "C" {
#endif

    #include <stdint.h>
    #include <string.h>
    
    typedef struct{
        uint32_t *field; /*-> points to the used-defined memory block to hol th */
        size_t size;     /*-> Bits capacity*/
        size_t nSlots;   /*-> Number of 32-bit slots for the bitfield storage*/
    }bitfield_t;
    
    #define BITFIELD_SIZE(NBITS)     (4*(( (NBITS-1) / 32 ) + 1) )
    
        
    void bitfield_setup( bitfield_t *instance, void *area, size_t area_size );
    uint8_t bitfield_getbit( const bitfield_t *instance, size_t index);
    void bitfield_setbit( bitfield_t *instance, size_t index );
    void bitfield_clearbit( bitfield_t *instance, size_t index );
    void bitfield_togglebit( bitfield_t *instance, size_t index );
    void bitfield_writebit( bitfield_t *instance, size_t index, uint8_t value );
    
    uint32_t bitfield_read_uint32(const bitfield_t *instance, size_t index );
    void bitfield_write_uint32( bitfield_t *instance, size_t index, uint32_t value );

    uint32_t bitfield_read_uintn( bitfield_t *instance, size_t index, size_t xbits );
    void bitfield_write_uintn( bitfield_t *instance, size_t index, uint32_t value, size_t xbits );
    
    float bitfield_read_float(const bitfield_t *instance, size_t index );
    void bitfield_write_float( bitfield_t *instance, size_t index, float value );
  
    
#ifdef __cplusplus
}
#endif

#endif /* BITFIELD_H */

