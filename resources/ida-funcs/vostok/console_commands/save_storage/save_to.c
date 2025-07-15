void __userpurge vostok::console_commands::save_storage::save_to(
        vostok::console_commands::save_storage *this@<ecx>,
        survarium::anomaly_state ***a2@<eax>,
        vostok::memory::writer *f)
{
  survarium::anomaly_state **v5; // ecx
  survarium::anomaly_state **v6; // esi
  int v7; // eax
  int v8; // edx
  const void **v9; // esi
  char **__first; // [esp+14h] [ebp+8h]
  survarium::anomaly_state **__firsta; // [esp+14h] [ebp+8h]

  v5 = *a2;
  v6 = a2[1];
  __first = (char **)*a2;
  if ( *a2 != v6 )
  {
    v7 = v6 - v5;
    v8 = 0;
    while ( v7 != 1 )
    {
      ++v8;
      v7 >>= 1;
    }
    stlp_std::priv::__introsort_loop<char const * *,char const *,int,bool (__cdecl *)(char const *,char const *)>(
      v5,
      v6,
      0,
      2 * v8,
      (survarium::anomaly_state **)vostok::strings::less);
    stlp_std::priv::__final_insertion_sort<char const * *,bool (__cdecl *)(char const *,char const *)>(
      (const char **)__first,
      (const char **)v6);
  }
  v9 = (const void **)*a2;
  __firsta = a2[1];
  if ( *a2 != __firsta )
  {
    do
    {
      f->write(f, *v9, strlen((const char *)*v9));
      f->write(f, "\r\n", 2u);
      ++v9;
    }
    while ( v9 != (const void **)__firsta );
  }
}
