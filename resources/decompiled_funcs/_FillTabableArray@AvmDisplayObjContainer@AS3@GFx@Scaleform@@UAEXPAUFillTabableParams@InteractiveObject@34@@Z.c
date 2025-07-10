void __thiscall Scaleform::GFx::AS3::AvmDisplayObjContainer::FillTabableArray(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::InteractiveObject::FillTabableParams *params)
{
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v2; // esi
  const char *pClassName; // ecx
  Scaleform::GFx::InteractiveObject::FillTabableParams *v4; // edi
  int v5; // ebp
  int v6; // esi
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy> > *Array; // ecx
  int v8; // [esp+4h] [ebp-8h]
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v9; // [esp+8h] [ebp-4h]

  v2 = this;
  pClassName = this[-1].pClassName;
  v9 = v2;
  if ( *((_DWORD *)pClassName + 32) && (*((_DWORD *)pClassName + 26) & 0x8000) == 0 )
  {
    v4 = params;
    v5 = 0;
    v8 = *((_DWORD *)pClassName + 32);
    while ( 1 )
    {
      v6 = *(_DWORD *)(*((_DWORD *)v2[-1].pClassName + 31) + v5);
      if ( v6 && *(char *)(v6 + 62) < 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 228))(v6) )
      {
        if ( *(__int16 *)(v6 + 108) > 0 && !v4->TabIndexed )
        {
          Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &v4->Array->Data,
            v4->Array->Data.pHeap,
            0);
          v4->TabIndexed = 1;
        }
        if ( ((*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 340))(v6)
           || v4->InclFocusEnabled && (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v6 + 348))(v6, 2))
          && (!v4->TabIndexed || *(__int16 *)(v6 + 108) > 0) )
        {
          ++*(_DWORD *)(v6 + 4);
          Array = v4->Array;
          params = (Scaleform::GFx::InteractiveObject::FillTabableParams *)v6;
          Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>>::PushBack(
            Array,
            (const Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&params);
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v6);
        }
        if ( (*(_WORD *)(v6 + 62) & 0x200) != 0 )
          Scaleform::GFx::DisplayObjContainer::FillTabableArray((Scaleform::GFx::DisplayObjContainer *)v6, v4);
      }
      v5 += 12;
      if ( !--v8 )
        break;
      v2 = v9;
    }
  }
}
