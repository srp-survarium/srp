void __cdecl _initp_misc_winsig(void (__cdecl *enull)(int))
{
  ctrlc_action = enull;
  ctrlbreak_action = enull;
  abort_action = enull;
  term_action = enull;
}
