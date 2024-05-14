#ifdef DEBUG
extern FILE *dbgf;

#define D_MIN   0x00010000
#define D_MED   0x00020000
#define D_MAX   0x00040000
#define D_FLUSH 0x00080000
#define D_TRACE 0x00100000
#define D_1     0x00000001

#define D(msk, fmt, args...) if(msk & dbgmsk) { fprintf(dbgf, "%s\t", __FUNCTION__); fprintf(dbgf, fmt, ## args); if (msk & D_FLUSH) fflush(dbgf); }
#define P(msk, fmt, args...) if(msk & dbgmsk) { fprintf(dbgf, fmt, ##args); if (msk & D_FLUSH) fflush(dbgf); }

#else

#define D(msk, fmt, args...)
#define P(msk, fmt, args...)

#endif
