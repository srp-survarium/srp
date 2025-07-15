void __thiscall Scaleform::Render::SKI_Primitive::DrawBundleEntry(
        Scaleform::Render::SKI_Primitive *this,
        void *__formal,
        Scaleform::Render::BundleEntry *p,
        Scaleform::Render::Renderer2DImpl *a4)
{
  Scaleform::Render::Bundle *pObject; // eax
  Scaleform::ArrayDefaultPolicy *p_Policy; // edx
  int v6; // ecx
  void (__thiscall *v7)(int, _DWORD *); // edx
  _DWORD v8[2]; // [esp+0h] [ebp-8h] BYREF

  pObject = p->pBundle.pObject;
  if ( pObject )
  {
    if ( pObject == (Scaleform::Render::Bundle *)-40 )
      p_Policy = 0;
    else
      p_Policy = &pObject[1].Entries.Data.Policy;
    v6 = *(_DWORD *)(pObject[1].RefCount + 40);
    v8[0] = p_Policy;
    v7 = *(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v6 + 124);
    v8[1] = 0;
    v7(v6, v8);
  }
}
