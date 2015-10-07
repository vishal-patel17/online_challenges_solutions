/* Input

There is a single positive integer T on the first line of input (equal to about 100000). It stands for the number of numbers to follow. Then there are T lines, each containing exactly one positive integer number N, 1 <= N <= 1000000000.

Output

For every number N, output a single line containing the single non-negative integer Z(N).
Example

Sample Input:

6
3
60
100
1024
23456
8735373
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <inttypes.h>

typedef unsigned int uint_t;
const uint_t T_MAX = 100000, N_MAX = 1000000000;

static uint16_t a[78125];

void do_prep()
{
    for (uint_t i = 0; i < 15625; i++) {
        uint_t i5 = i * 5;
        uint_t v = i + a[i];
        assert (v < 65536);
        for (uint_t j = 0; j < 5; j++)
            a[i5 + j] = v;
    }
}


static inline uint_t do_calc(uint_t n)
{
    uint_t q = n / 78125, r = n % 78125;
    return 19531 * q + a[q] + a[r];
}


class RawReader
{
    static const uint_t D = 10;
    static const uint_t RBUF_SIZE = 8192;
    char rbuf[RBUF_SIZE];

    char *rlim, *rpos;
    int rrlen, reof;

    char* read_more(char *rpos)
    {
        int l, s, t;
        char *p;

        if (reof)
            return rpos;

        l = rrlen - (rpos - rbuf);
        if (rpos != rbuf)
            memmove(rbuf, rpos, l);
        rpos = rbuf;
        p = rbuf + l;
        t = sizeof(rbuf) - l;
        s = read(0, p, t);
        if (s < 0)
            s = 0;
        rrlen = l + s;
        rlim = rpos + rrlen;
        if (s <= 0) {
            reof = 1;
        }

        return rpos;
    }

public:
    void init(void)
    {
        rrlen = 0;
        reof = 0;
        rlim = rbuf;
        rpos = rbuf;
    }

    inline int rnextf() { return *rpos++; }

    inline int rnext()
    {
        if (rlim - rpos <= 0)
            rpos = read_more(rpos);
        return (rlim - rpos > 0) ? rnextf() : -1;
    }

    inline uint32_t getu32()
    {
        if (rlim - rpos < 12)
            rpos = read_more(rpos);

        uint32_t v;
        do {
            v = rnextf() - '0';
        } while (v >= D);

        uint32_t res = v;

        for (;;) {
            v = rnextf() - '0';
            if (v >= D)
                break;
            res = res * D + v;
        }

        return res;
    }

};


class RawWriter
{
    static const uint_t WBUF_SIZE = 8192;
    char wbuf[WBUF_SIZE];

    char *wlim, *wpos;
    int werr;

    static bool sinit_ok;
    static const uint_t D = 10, K = 3, DPK = 1000;
    static char dgroups[DPK][4];

    static void sinit()
    {
        if (sinit_ok)
            return;

        char dg[K];
        for (uint_t j = 0; j < K; j++)
            dg[j] = '0';

        for (uint_t i = 0; i < DPK; i++) {
            char *dgroup = dgroups[i];
            for (uint_t j = 0; j < K; j++)
                dgroup[j] = dg[j];

            for (uint_t j = 0; j < K; j++) {
                dg[j]++;
                if (dg[j] != '0' + D)
                    break;
                dg[j] = '0';
            }
        }

        sinit_ok = 1;
    }


public:
    void write_all()
    {
        ssize_t len = wpos - wbuf;
        if (len <= 0)
            return;
        ssize_t r = write(1, wbuf, len);
        if (r != len) {
            fprintf(
                    stderr,
                    "RawWriter: cannot write buffer, r=%d, errno=%d \n",
                    (int) r, errno
            );
            abort();
        }

        wpos = wbuf;
    }

    void init()
    {
        sinit();
        wpos = wbuf;
        wlim = wbuf + WBUF_SIZE;
    }

    inline void wnextf(char c) { *wpos++ = c; }

    inline void wnext(char c)
    {
        if (wlim - wpos <= 0)
            write_all();
        *wpos++ = c;
    }

    void putu32(uint32_t x)
    {
        char buf[12];
        uint_t l = 0;
        while (x >= DPK) {
            uint32_t r = x % DPK;
            x = x / DPK;
            const char *dgroup = dgroups[r];
            for (uint_t i = 0; i < K; i++) {
                buf[l + i] = dgroup[i];
            }
            l += K;
        }
        {
            uint32_t r = x;
            const char *dgroup = dgroups[r];
            for (uint_t i = 0; i < K; i++) {
                buf[l + i] = dgroup[i];
            }
            l += K;
        }

        do {
            l--;
        } while (buf[l] == '0' && l > 0);

        l++;
        buf[l] = 0;

        if (wlim - wpos <= l)
            write_all();

        while (l > 0) {
            l--;
            *wpos++ = buf[l];
        }
        *wpos++ = '\n';
    }

};

bool RawWriter::sinit_ok;
char RawWriter::dgroups[DPK][4];


int main()
{
    do_prep();

    uint_t t;
    RawWriter rw;
    rw.init();

    RawReader rr;
    rr.init();
    t = rr.getu32();

    assert (t <= T_MAX);
    for (uint_t i = 0; i < t; i++) {
        uint_t n;
        n = rr.getu32();
        uint_t res = do_calc(n);
        rw.putu32(res);
    }

    rw.write_all();

    return 0;
}