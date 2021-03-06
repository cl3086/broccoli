/*
       B R O C C O L I  --  The Bro Client Communications Library

Copyright (C) 2004-2008 Christian Kreibich <christian (at) icir.org>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to
deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies of the Software and its documentation and acknowledgment shall be
given in the documentation and software packages that this Software was
used.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/
#if HAVE_CONFIG_H
# include <config.h>
#endif

#include <bro_shm.h>

struct bro_shared_mem {
  void    *mem;
  int      mem_size;
};

BroSharedMem  *
__bro_shm_new(int size)
{
  BroSharedMem *shm;

  if (size <= 0)
    return NULL;

  if (! (shm = calloc(1, sizeof(BroSharedMem))))
    return NULL;
  
  if (! (shm->mem = malloc(size)))
    {
      free(shm);
      return NULL;
    }

  shm->mem_size = size;

  return shm;
}


void
__bro_shm_free(BroSharedMem *shm)
{
  if (! shm)
    return;

  if (shm->mem)
    free(shm->mem);

  free(shm);
}


void *
__bro_shm_get_mem(const BroSharedMem *shm)
{
  if (! shm)
    return NULL;

  return shm->mem;
}


int
__bro_shm_get_size(const BroSharedMem *shm)
{
  return shm->mem_size;
}


int
__bro_shm_attach(BroSharedMem *shm)
{
  return TRUE; 
  shm = NULL;
}


int
__bro_shm_detach(BroSharedMem *shm)
{
  return TRUE;
  shm = NULL;
}
