#ifndef FLAGTABLE_H_
#define FLAGTABLE_H_
/* flag_table.h :: TODO document
 *
 */


/* TODO document */
typedef enum {

} Flags;


/* TODO document
 *
 */
typedef struct flaglookuptable{
/* TODO implement */
    /* NOTES
     *
     * - the flags are just enums, the number of the enum is the index in the table,
     *   the table stores true or false values at those indexes to indicate whather a flag
     *   is "in the table" / "active" (with a true at that index) or not (with a false)
     *
     * 2 function pointers
     * - contains :: returns true if it is contained in the table, false if not
     * - put, puts the flag in the table, or does nothing if it is already in it
     *
     *
     */
} FlagLookupTable;


#endif
