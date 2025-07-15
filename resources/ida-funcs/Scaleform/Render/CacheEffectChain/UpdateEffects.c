char __thiscall Scaleform::Render::CacheEffectChain::UpdateEffects(
        Scaleform::Render::CacheEffectChain *this,
        Scaleform::Render::TreeCacheNode *node,
        unsigned int changeFlags)
{
  Scaleform::Render::TreeNode *pNode; // eax
  Scaleform::Render::CacheEffect *pEffect; // esi
  Scaleform::Render::StateBag *v6; // ebx
  unsigned int i; // edi
  Scaleform::Render::StateType Type; // ebp
  Scaleform::Render::CacheEffect *pNext; // ebp
  unsigned int State; // eax
  Scaleform::Render::CacheEffect_vtbl *v11; // edx
  const Scaleform::Render::State *v12; // eax
  struct Scaleform::Render::CacheEffect *v13; // eax
  char v14; // [esp+5h] [ebp-Dh]
  Scaleform::Render::CacheEffectChain *p_pNext; // [esp+6h] [ebp-Ch]
  Scaleform::Render::StateBag *v16; // [esp+Ah] [ebp-8h]
  Scaleform::Render::StateType v17; // [esp+Eh] [ebp-4h]

  pNode = node->pNode;
  v14 = 0;
  if ( !pNode )
    return 0;
  pEffect = this->pEffect;
  v6 = (Scaleform::Render::StateBag *)((*(_DWORD *)(*(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x14)
                                                  + 4
                                                  * ((int)((int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000))
                                                   / 28)
                                                  + 20)
                                      & 0xFFFFFFFE)
                                     + 64);
  v16 = v6;
  p_pNext = this;
  if ( !this->pEffect && !v6->ArraySize )
    return 0;
  for ( i = 0; i < 0x48; i += 12 )
  {
    if ( pEffect
      && (Type = Scaleform::Render::ChainOrderSequence[i / 0xC].Type, v17 = Type, pEffect->GetType(pEffect) == Type) )
    {
      pNext = pEffect->pNext;
      if ( (changeFlags & dword_8754DC[i / 4]) != 0 )
      {
        State = Scaleform::Render::StateBag::GetState(v16, v17);
        v11 = pEffect->__vftable;
        if ( !State )
        {
          ((void (__thiscall *)(Scaleform::Render::CacheEffect *, int))v11->~Scaleform::Render::CacheEffect)(pEffect, 1);
          v6 = v16;
          p_pNext->pEffect = pNext;
          v14 = 1;
          pEffect = pNext;
          continue;
        }
        v14 |= ((int (__thiscall *)(Scaleform::Render::CacheEffect *, unsigned int))v11->Update)(pEffect, State);
      }
      p_pNext = (Scaleform::Render::CacheEffectChain *)&pEffect->pNext;
      v6 = v16;
      pEffect = pNext;
    }
    else if ( (changeFlags & dword_8754DC[i / 4]) != 0 )
    {
      v12 = (const Scaleform::Render::State *)Scaleform::Render::StateBag::GetState(
                                                v6,
                                                Scaleform::Render::ChainOrderSequence[i / 0xC].Type);
      if ( v12 )
      {
        v13 = (*(struct Scaleform::Render::CacheEffect *(__cdecl **)(Scaleform::Render::TreeCacheNode *, const Scaleform::Render::State *, Scaleform::Render::CacheEffect *))((char *)&off_8754E0 + i))(
                node,
                v12,
                pEffect);
        if ( v13 )
        {
          p_pNext->pEffect = v13;
          p_pNext = (Scaleform::Render::CacheEffectChain *)&v13->pNext;
        }
      }
    }
  }
  return v14;
}
