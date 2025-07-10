char __thiscall Scaleform::Render::CacheEffectChain::UpdateEffects(
        Scaleform::Render::CacheEffectChain *this,
        Scaleform::Render::TreeCacheNode *node,
        unsigned int changeFlags)
{
  Scaleform::Render::TreeNode *pNode; // eax
  Scaleform::Render::CacheEffect *pEffect; // esi
  Scaleform::Render::StateBag *v6; // ebx
  unsigned int i; // edi
  Scaleform::Render::StateType v8; // ebp
  Scaleform::Render::CacheEffect *pNext; // ebp
  unsigned int State; // eax
  Scaleform::Render::CacheEffect_vtbl *v11; // edx
  const Scaleform::Render::State *v12; // eax
  struct Scaleform::Render::CacheEffect *v13; // eax
  char updateParent; // [esp+5h] [ebp-Dh]
  Scaleform::Render::CacheEffectChain *prevEffectPointer; // [esp+6h] [ebp-Ch]
  Scaleform::Render::StateBag *states; // [esp+Ah] [ebp-8h]
  Scaleform::Render::StateType type; // [esp+Eh] [ebp-4h]

  pNode = node->pNode;
  updateParent = 0;
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
  states = v6;
  prevEffectPointer = this;
  if ( !this->pEffect && !v6->ArraySize )
    return 0;
  for ( i = 0; i < 0x48; i += 12 )
  {
    if ( pEffect
      && (v8 = Scaleform::Render::ChainOrderSequence[i / 0xC].Type, type = v8, pEffect->GetType(pEffect) == v8) )
    {
      pNext = pEffect->pNext;
      if ( (changeFlags & dword_9B3CAC[i / 4]) != 0 )
      {
        State = Scaleform::Render::StateBag::GetState(states, type);
        v11 = pEffect->__vftable;
        if ( !State )
        {
          ((void (__thiscall *)(Scaleform::Render::CacheEffect *, int))v11->~Scaleform::Render::CacheEffect)(pEffect, 1);
          v6 = states;
          prevEffectPointer->pEffect = pNext;
          updateParent = 1;
          pEffect = pNext;
          continue;
        }
        updateParent |= ((int (__thiscall *)(Scaleform::Render::CacheEffect *, unsigned int))v11->Update)(
                          pEffect,
                          State);
      }
      prevEffectPointer = (Scaleform::Render::CacheEffectChain *)&pEffect->pNext;
      v6 = states;
      pEffect = pNext;
    }
    else if ( (changeFlags & dword_9B3CAC[i / 4]) != 0 )
    {
      v12 = (const Scaleform::Render::State *)Scaleform::Render::StateBag::GetState(
                                                v6,
                                                Scaleform::Render::ChainOrderSequence[i / 0xC].Type);
      if ( v12 )
      {
        v13 = (*(struct Scaleform::Render::CacheEffect *(__cdecl **)(Scaleform::Render::TreeCacheNode *, const Scaleform::Render::State *, Scaleform::Render::CacheEffect *))((char *)&off_9B3CB0 + i))(
                node,
                v12,
                pEffect);
        if ( v13 )
        {
          prevEffectPointer->pEffect = v13;
          prevEffectPointer = (Scaleform::Render::CacheEffectChain *)&v13->pNext;
        }
      }
    }
  }
  return updateParent;
}
