int __thiscall Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp::operator()(
        Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp *this,
        const Scaleform::GFx::ResourceWeakLib::ResourceNode *node)
{
  char v2; // bl
  Scaleform::GFx::ResourceKey *p_Key; // esi
  Scaleform::GFx::ResourceKey::KeyInterface *pKeyInterface; // edi
  void *hKeyData; // esi
  int v6; // ebx
  _DWORD v8[2]; // [esp+Ch] [ebp-8h] BYREF

  v2 = 0;
  v8[0] = 0;
  if ( node->Type )
  {
    p_Key = &node->pResolver->Key;
  }
  else
  {
    v2 = 1;
    p_Key = (Scaleform::GFx::ResourceKey *)((int (__thiscall *)(Scaleform::GFx::ResourceLib::ResourceSlot *, _DWORD *))node->pResolver->__vftable[1].~Scaleform::GFx::ResourceLib::ResourceSlot)(
                                             node->pResolver,
                                             v8);
  }
  if ( p_Key->pKeyInterface )
    p_Key->pKeyInterface->AddRef(p_Key->pKeyInterface, p_Key->hKeyData);
  pKeyInterface = p_Key->pKeyInterface;
  hKeyData = p_Key->hKeyData;
  if ( (v2 & 1) != 0 && v8[0] )
    (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v8[0] + 8))(v8[0], v8[1]);
  if ( !pKeyInterface )
    return 0;
  v6 = pKeyInterface->GetHashCode(pKeyInterface, hKeyData);
  pKeyInterface->Release(pKeyInterface, hKeyData);
  return v6;
}
