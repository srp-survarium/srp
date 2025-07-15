void __thiscall Scaleform::System::`default constructor closure'(Scaleform::System *this)
{
  if ( (`Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc>::InitSystemSingleton'::`2'::`local static guard'
      & 1) == 0 )
    `Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc>::InitSystemSingleton'::`2'::`local static guard' |= 1u;
  `Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc>::InitSystemSingleton'::`2'::Container.__vftable = (Scaleform::SysAllocBase_vtbl *)&Scaleform::SysAllocMalloc::`vftable';
  dword_47EAA78 = (int)&`Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc>::InitSystemSingleton'::`2'::Container;
  byte_47EAA7C = 1;
  Scaleform::System::Init(&`Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc>::InitSystemSingleton'::`2'::Container);
}
