void **__cdecl stlp_std::priv::__copy_ptrs<void * *,void * *>(void **__first, void **__last, void **__result)
{
  return (void **)stlp_std::priv::__copy_trivial(
                    (unsigned __int8 *)__first,
                    (unsigned __int8 *)__last,
                    (unsigned __int8 *)__result);
}
