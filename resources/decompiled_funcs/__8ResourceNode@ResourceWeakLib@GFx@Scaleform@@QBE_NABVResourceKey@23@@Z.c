char __thiscall Scaleform::GFx::ResourceWeakLib::ResourceNode::operator==(
        Scaleform::GFx::ResourceWeakLib::ResourceNode *this,
        const Scaleform::GFx::ResourceKey *k)
{
  _DWORD *v2; // eax
  char v3; // bl
  Scaleform::GFx::ResourceLib::ResourceSlot *pResolver; // eax
  Scaleform::GFx::ResourceKey::KeyInterface *pKeyInterface; // ecx
  Scaleform::GFx::ResourceKey *p_Key; // eax
  _DWORD v8[2]; // [esp+4h] [ebp-8h] BYREF

  if ( this->Type )
  {
    pResolver = this->pResolver;
    pKeyInterface = pResolver->Key.pKeyInterface;
    p_Key = &pResolver->Key;
    return pKeyInterface && k->pKeyInterface && pKeyInterface->KeyEquals(pKeyInterface, p_Key->hKeyData, k);
  }
  else
  {
    v2 = (_DWORD *)((int (__thiscall *)(Scaleform::GFx::ResourceLib::ResourceSlot *, _DWORD *))this->pResolver->__vftable[1].~Scaleform::GFx::ResourceLib::ResourceSlot)(
                     this->pResolver,
                     v8);
    if ( *v2 && k->pKeyInterface )
      v3 = (*(int (__thiscall **)(_DWORD, _DWORD, const Scaleform::GFx::ResourceKey *))(*(_DWORD *)*v2 + 20))(
             *v2,
             v2[1],
             k);
    else
      v3 = 0;
    if ( v8[0] )
      (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v8[0] + 8))(v8[0], v8[1]);
    return v3;
  }
}
