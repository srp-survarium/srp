void __cdecl Scaleform::ConstructorMov<Scaleform::Waitable::HandlerStruct>::ConstructArray(
        void (__cdecl **p)(void *),
        unsigned int count,
        const Scaleform::Waitable::HandlerStruct *psource)
{
  unsigned int i; // edx

  for ( i = count; i; --i )
  {
    if ( p )
    {
      *p = psource->Handler;
      p[1] = (void (__cdecl *)(void *))psource->pUserData;
    }
    ++psource;
    p += 2;
  }
}
