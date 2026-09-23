#include <nfd.h>
#include <nfd.hpp>

#undef NDEBUG
#include <cassert>

int main ()
{
  // Exercise both the C API and the C++ wrapper, which in turn calls the
  // exported (non-inline) NFD_Init()/NFD_Quit() symbols.
  //
  assert (NFD_Init () == NFD_OKAY);
  NFD_Quit ();

  assert (NFD::Init () == NFD_OKAY);
  NFD::Quit ();
}
