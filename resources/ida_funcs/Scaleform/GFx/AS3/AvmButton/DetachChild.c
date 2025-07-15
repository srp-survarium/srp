char __thiscall Scaleform::GFx::AS3::AvmButton::DetachChild(
        Scaleform::GFx::AS3::AvmButton *this,
        Scaleform::GFx::DisplayObjectBase *child)
{
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType **p_pPerspectiveData; // ebp
  char v3; // bl
  Scaleform::Render::ContextImpl::Entry *v4; // edi
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v5; // ecx
  unsigned int v6; // eax
  Scaleform::Render::TreeContainer *pParent; // ebp
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  unsigned int v11; // ebx
  _DWORD *v12; // eax
  bool v13; // zf
  unsigned int v15; // [esp+10h] [ebp-1Ch]
  Scaleform::Render::ContextImpl::Entry *v16; // [esp+14h] [ebp-18h]
  unsigned int j; // [esp+18h] [ebp-14h]
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType **v18; // [esp+1Ch] [ebp-10h]
  int v19; // [esp+20h] [ebp-Ch]
  Scaleform::Render::TreeNode *v20; // [esp+24h] [ebp-8h]
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v21; // [esp+28h] [ebp-4h]

  p_pPerspectiveData = &this->pDispObj[1].pPerspectiveData;
  v3 = 0;
  v18 = p_pPerspectiveData;
  v19 = 3;
  do
  {
    v4 = (Scaleform::Render::ContextImpl::Entry *)*(p_pPerspectiveData - 2);
    v16 = v4;
    if ( v4 )
      ++v4->RefCount;
    v5 = *p_pPerspectiveData;
    v21 = *p_pPerspectiveData;
    if ( *p_pPerspectiveData )
    {
      v6 = 0;
      j = 0;
      do
      {
        if ( *((Scaleform::GFx::DisplayObjectBase **)&(*(p_pPerspectiveData - 1))->FieldOfView + 2 * v6) == child )
        {
          child->pParent = 0;
          if ( Scaleform::GFx::DisplayObjectBase::GetRenderNode(child) )
          {
            pParent = (Scaleform::Render::TreeContainer *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(child)->pParent;
            if ( pParent )
            {
              v8 = *(_DWORD *)(*(_DWORD *)(((unsigned int)pParent & 0xFFFFF000) + 0x10)
                             + 4 * ((int)((int)&pParent[-1] - ((unsigned int)pParent & 0xFFFFF000)) / 28)
                             + 20);
              v9 = *(_DWORD *)(v8 + 144);
              v10 = v8 + 144;
              v11 = 0;
              if ( v9 )
              {
                v15 = (v9 & 1) != 0 ? *(_DWORD *)((v9 & 0xFFFFFFFE) + 4) : (*(_DWORD *)(v10 + 4) != 0) + 1;
                if ( v15 )
                {
                  while ( 1 )
                  {
                    v12 = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(((unsigned int)pParent & 0xFFFFF000) + 0x10)
                                               + 4
                                               * ((int)((int)&pParent[-1] - ((unsigned int)pParent & 0xFFFFF000))
                                                / 28)
                                               + 20)
                                   + 144);
                    if ( (*(_BYTE *)v12 & 1) != 0 )
                      v12 = (_DWORD *)((*v12 & 0xFFFFFFFE) + 8);
                    v20 = (Scaleform::Render::TreeNode *)v12[v11];
                    if ( v20 == Scaleform::GFx::DisplayObjectBase::GetRenderNode(child) )
                      break;
                    if ( ++v11 >= v15 )
                      goto LABEL_20;
                  }
                  Scaleform::Render::TreeContainer::Remove(pParent, v11, 1u);
LABEL_20:
                  v4 = v16;
                }
              }
            }
          }
          p_pPerspectiveData = v18;
          v5 = v21;
          v6 = j;
          v3 = 1;
        }
        j = ++v6;
      }
      while ( v6 < (unsigned int)v5 );
    }
    if ( v4 )
    {
      v13 = v4->RefCount-- == 1;
      if ( v13 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v4);
    }
    p_pPerspectiveData += 4;
    v13 = v19-- == 1;
    v18 = p_pPerspectiveData;
  }
  while ( !v13 );
  return v3;
}
