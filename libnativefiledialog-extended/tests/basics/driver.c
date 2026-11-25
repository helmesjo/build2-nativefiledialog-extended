#include <stddef.h>

#include <nfd.h>

#undef NDEBUG
#include <assert.h>

int main (void)
{
  /* On Linux NFD_Init() fails without a display (GTK backend) or without a
   * D-Bus session bus (portal backend), which a headless test machine may
   * not have. In that case it must return NFD_ERROR and set an error.
   */
  nfdresult_t r = NFD_Init ();

  if (r == NFD_OKAY)
    NFD_Quit ();
  else
  {
    assert (r == NFD_ERROR);
    assert (NFD_GetError () != NULL);

    NFD_ClearError ();
    assert (NFD_GetError () == NULL);
  }

  return 0;
}
