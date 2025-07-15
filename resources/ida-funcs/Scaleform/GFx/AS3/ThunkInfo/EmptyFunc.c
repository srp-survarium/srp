void __cdecl Scaleform::GFx::AS3::ThunkInfo::EmptyFunc(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm)
{
  char *NamespaceName; // eax
  char *Name; // eax
  void *v4; // esi
  Scaleform::String str; // [esp+8h] [ebp-4h] BYREF

  Scaleform::String::String(&str, "The method ");
  NamespaceName = (char *)ti->NamespaceName;
  if ( NamespaceName )
  {
    Scaleform::String::AppendString(&str, NamespaceName, 0xFFFFFFFF);
    Scaleform::String::AppendString(&str, "::", 0xFFFFFFFF);
  }
  Name = (char *)ti->Name;
  if ( Name )
  {
    Scaleform::String::AppendString(&str, Name, 0xFFFFFFFF);
    Scaleform::String::AppendString(&str, "()", 0xFFFFFFFF);
  }
  Scaleform::String::AppendString(&str, " is not implemented\n", 0xFFFFFFFF);
  vm->UI->Output(vm->UI, Output_Warning, (const char *)((str.HeapTypeBits & 0xFFFFFFFC) + 8));
  v4 = (void *)(str.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((str.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
}
