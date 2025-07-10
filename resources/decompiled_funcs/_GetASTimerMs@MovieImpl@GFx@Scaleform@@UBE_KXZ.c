int __thiscall Scaleform::GFx::MovieImpl::GetASTimerMs(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::RefCountVImpl *v2; // eax
  _DWORD *v3; // esi
  int v4; // edi
  unsigned __int64 v5; // kr00_8
  __int64 v6; // rax
  void *v7; // esi
  Scaleform::String tstr; // [esp+Ch] [ebp-54h] BYREF
  Scaleform::LongFormatter f; // [esp+10h] [ebp-50h] BYREF

  v2 = (Scaleform::RefCountVImpl *)this->GetStateAddRef(&this->Scaleform::GFx::StateBag, 31);
  v3 = &v2->__vftable;
  if ( !v2 )
    return Scaleform::Timer::GetTicks() / 0x3E8 - this->StartTickMs;
  Scaleform::RefCountImpl::Release(v2);
  if ( v3[3] )
  {
    Scaleform::String::String(&tstr);
    (*(void (__thiscall **)(_DWORD *, const char *, Scaleform::String *))(*v3 + 4))(v3, "timer", &tstr);
    v4 = _strtoui64((unsigned int)v3, (const char *)((tstr.HeapTypeBits & 0xFFFFFFFC) + 8), 0, 10);
    v7 = (void *)(tstr.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((tstr.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
      LODWORD(v6) = v4;
      return v6;
    }
  }
  else
  {
    v5 = Scaleform::Timer::GetTicks() / 0x3E8 - this->StartTickMs;
    v4 = v5;
    Scaleform::LongFormatter::LongFormatter(&f, v5);
    Scaleform::LongFormatter::Convert(&f);
    (*(void (__thiscall **)(_DWORD *, const char *, char *))(*v3 + 8))(v3, "timer", f.ValueStr);
    f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
    Scaleform::Formatter::~Formatter(&f);
  }
  LODWORD(v6) = v4;
  return v6;
}
