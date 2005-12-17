/* Native-dependent code for GNU/Linux UltraSPARC.

   Copyright (C) 2003, 2005 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

#include "defs.h"

#include "sparc64-tdep.h"
#include "sparc-nat.h"
#include "inferior.h"
#include "target.h"
#include "linux-nat.h"

static const struct sparc_gregset sparc64_linux_ptrace_gregset =
{
  16 * 8,			/* "tstate" */
  17 * 8,			/* %pc */
  18 * 8,			/* %npc */
  19 * 8,			/* %y */
  -1,				/* %wim */
  -1,				/* %tbr */
  0 * 8,			/* %g1 */
  -1,				/* %l0 */
  4				/* sizeof (%y) */
};


/* Provide a prototype to silence -Wmissing-prototypes.  */
void _initialize_sparc64_linux_nat (void);

void
_initialize_sparc64_linux_nat (void)
{
  struct target_ops *t;

  /* Fill in the generic GNU/Linux methods.  */
  t = linux_target ();

  /* Add our register access methods.  */
  t->to_fetch_registers = fetch_inferior_registers;
  t->to_store_registers = store_inferior_registers;

  /* Register the target.  */
  add_target (t);

  sparc_gregset = &sparc64_linux_ptrace_gregset;
}
