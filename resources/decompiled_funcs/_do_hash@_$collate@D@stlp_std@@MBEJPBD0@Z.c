int __thiscall stlp_std::collate<char>::do_hash(stlp_std::collate<char> *this, const char *low, const char *high)
{
  const char *v3; // ecx
  int result; // eax
  int v5; // esi

  v3 = low;
  for ( result = 0; v3 < high; result = v5 + 5 * result )
    v5 = *v3++;
  return result;
}
