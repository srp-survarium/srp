void __cdecl stlp_std::priv::_Initialize_get_float(
        const stlp_std::ctype<wchar_t> *ct,
        wchar_t *Plus,
        wchar_t *Minus,
        wchar_t *pow_e,
        wchar_t *pow_E,
        wchar_t *digits)
{
  char v6[12]; // [esp+18h] [ebp-10h] BYREF

  strcpy(v6, "0123456789");
  *Plus = ct->do_widen(ct, 43);
  *Minus = ct->do_widen(ct, 45);
  *pow_e = ct->do_widen(ct, 101);
  *pow_E = ct->do_widen(ct, 69);
  ct->do_widen(ct, v6, &v6[10], digits);
}
