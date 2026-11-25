#include <nfd.hpp>

#undef NDEBUG
#include <cassert>

int main ()
{
  // The same as driver.c but through the C++ wrapper.
  //
  nfdresult_t r (NFD::Init ());

  if (r == NFD_OKAY)
    NFD::Quit ();
  else
  {
    assert (r == NFD_ERROR);
    assert (NFD::GetError () != nullptr);

    NFD::ClearError ();
    assert (NFD::GetError () == nullptr);
  }
}
