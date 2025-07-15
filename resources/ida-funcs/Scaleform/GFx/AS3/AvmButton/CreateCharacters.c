void __thiscall Scaleform::GFx::AS3::AvmButton::CreateCharacters(Scaleform::GFx::AS3::AvmButton *this)
{
  Scaleform::GFx::AS3::AvmButton *v1; // esi
  char *pClassName; // edi
  int v3; // ebx
  int v4; // ebx
  char v5; // al
  Scaleform::Render::TreeContainer *v6; // eax
  Scaleform::Ptr<Scaleform::Render::TreeContainer> *v7; // eax
  Scaleform::Render::TreeContainer *pObject; // edx
  Scaleform::Render::TreeContainer *v9; // eax
  int v10; // ecx
  int v11; // eax
  Scaleform::GFx::InteractiveObject *v12; // esi
  Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *v13; // ecx
  unsigned int v14; // eax
  unsigned int v15; // edi
  _DWORD *v16; // edi
  unsigned int Flags; // eax
  int v18; // eax
  int v19; // eax
  unsigned int v20; // ecx
  int v21; // eax
  Scaleform::GFx::DisplayObjectBase *v22; // eax
  int v23; // edx
  double v24; // st7
  char v25; // al
  int v26; // ecx
  const char *v27; // ecx
  int v28; // eax
  int v29; // edi
  Scaleform::GFx::ASStringNode *v30; // eax
  void (__thiscall *v31)(struct Scaleform::RefCountNTSImpl *); // eax
  Scaleform::Render::ContextImpl::Entry *v32; // ecx
  unsigned int v33; // edi
  int v34; // eax
  unsigned int v35; // ecx
  int v36; // eax
  Scaleform::GFx::ButtonRecord::MouseState v38; // [esp+5FCh] [ebp-D4h]
  char v39; // [esp+612h] [ebp-BEh]
  unsigned __int8 v40; // [esp+613h] [ebp-BDh]
  Scaleform::Render::TreeContainer *v41; // [esp+614h] [ebp-BCh]
  Scaleform::GFx::Button::ButtonState buttonState; // [esp+618h] [ebp-B8h]
  Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *pheapAddr; // [esp+61Ch] [ebp-B4h]
  int v44; // [esp+620h] [ebp-B0h]
  Scaleform::Render::TreeNode *RenderNode; // [esp+620h] [ebp-B0h]
  char *v47; // [esp+628h] [ebp-A8h]
  Scaleform::RefCountNTSImpl *v48; // [esp+62Ch] [ebp-A4h]
  int v49; // [esp+630h] [ebp-A0h]
  Scaleform::RefCountNTSImpl **p_pObject; // [esp+634h] [ebp-9Ch]
  Scaleform::GFx::DisplayObjectBase *v51; // [esp+638h] [ebp-98h]
  Scaleform::GFx::ASStringNode *v52; // [esp+63Ch] [ebp-94h] BYREF
  int v53; // [esp+640h] [ebp-90h]
  int v54; // [esp+644h] [ebp-8Ch]
  Scaleform::GFx::Button::ButtonState v55; // [esp+648h] [ebp-88h]
  Scaleform::Ptr<Scaleform::Render::TreeContainer> result; // [esp+64Ch] [ebp-84h] BYREF
  Scaleform::Render::Cxform v57; // [esp+650h] [ebp-80h] BYREF
  float v58; // [esp+670h] [ebp-60h]
  float v59; // [esp+674h] [ebp-5Ch]
  float v60; // [esp+678h] [ebp-58h]
  float v61; // [esp+67Ch] [ebp-54h]
  float v62; // [esp+680h] [ebp-50h]
  float v63; // [esp+684h] [ebp-4Ch]
  float v64; // [esp+688h] [ebp-48h]
  float v65; // [esp+68Ch] [ebp-44h]
  Scaleform::RefCountVImpl *v66; // [esp+690h] [ebp-40h]
  float v67; // [esp+694h] [ebp-3Ch]
  int v68; // [esp+698h] [ebp-38h]
  int v69; // [esp+69Ch] [ebp-34h]
  int v70; // [esp+6A0h] [ebp-30h]
  __int16 v71; // [esp+6A4h] [ebp-2Ch]
  __int16 v72; // [esp+6A6h] [ebp-2Ah]
  char v73; // [esp+6A8h] [ebp-28h]
  _BYTE v74[12]; // [esp+6B8h] [ebp-18h] BYREF
  int v75; // [esp+6C4h] [ebp-Ch] BYREF

  v1 = this;
  pClassName = (char *)this[-1].pClassName;
  v38 = *((_DWORD *)pClassName + 50);
  v47 = pClassName;
  v54 = *((_DWORD *)pClassName + 31);
  v3 = v54;
  v55 = Scaleform::GFx::Button::GetButtonState(v38);
  if ( !*(_DWORD *)(v54 + 24) )
    return;
  v49 = 0;
  v53 = *(_DWORD *)(v54 + 24);
  while ( 2 )
  {
    v4 = v49 + *(_DWORD *)(v3 + 20);
    v5 = 1;
    v40 = *(_BYTE *)(v4 + 80);
    v39 = 1;
    do
    {
      if ( ((unsigned __int8)v5 & v40) == 0 )
        goto LABEL_86;
      buttonState = None;
      if ( (v5 & 8) != 0 )
      {
        buttonState = None;
      }
      else if ( (v5 & 2) != 0 )
      {
        buttonState = 2;
      }
      else if ( (v5 & 4) != 0 )
      {
        buttonState = 1;
      }
      else if ( (v5 & 1) != 0 )
      {
        buttonState = 3;
      }
      pheapAddr = (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)&pClassName[16 * buttonState + 132];
      v6 = *(Scaleform::Render::TreeContainer **)&pClassName[16 * buttonState + 128];
      if ( v6 )
        ++v6->RefCount;
      v41 = v6;
      if ( !v6 )
      {
        v7 = Scaleform::GFx::Button::CreateStateRenderContainer(
               (Scaleform::GFx::Button *)pClassName,
               &result,
               buttonState);
        if ( v7->pObject )
          ++v7->pObject->RefCount;
        pObject = v7->pObject;
        v9 = result.pObject;
        v41 = pObject;
        if ( result.pObject )
        {
          --result.pObject->RefCount;
          if ( !v9->RefCount )
            Scaleform::Render::ContextImpl::Entry::destroyHelper(v9);
        }
      }
      if ( *(_DWORD *)&pClassName[16 * buttonState + 136] )
      {
        v22 = (pheapAddr->Data->Char.pObject->Flags & 0x400) != 0 ? pheapAddr->Data->Char.pObject : 0;
        if ( v22 )
          ++v22->RefCount;
        v48 = v22;
        goto LABEL_60;
      }
      Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
        *((Scaleform::GFx::MovieDefImpl **)v1[-1].pClassName + 25),
        (Scaleform::GFx::ResourceBinding *)v74,
        (Scaleform::GFx::ResourceId)65537);
      v10 = *(_DWORD *)(*((_DWORD *)v1[-1].pClassName + 4) + 12);
      v11 = (*(int (__thiscall **)(int, _DWORD, _BYTE *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v10 + 16))(
              v10,
              *(_DWORD *)(*((_DWORD *)v1[-1].pClassName + 4) + 8),
              v74,
              0,
              *(_DWORD *)(v4 + 68),
              0);
      v12 = (*(_WORD *)(v11 + 62) & 0x400) != 0 ? (Scaleform::GFx::InteractiveObject *)v11 : 0;
      v51 = (Scaleform::GFx::DisplayObjectBase *)v11;
      if ( v12 )
        ++v12->RefCount;
      v48 = v12;
      if ( v12 )
        ++v12->RefCount;
      v13 = (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)&pClassName[16 * buttonState + 132];
      v14 = *(_DWORD *)&pClassName[16 * buttonState + 136];
      v15 = v14 + 1;
      if ( v14 + 1 < v14 )
      {
        v44 = -1;
        p_pObject = &pheapAddr->Data[v14 - 1].Char.pObject;
        do
        {
          if ( *p_pObject )
          {
            Scaleform::RefCountNTSImpl::Release(*p_pObject);
            v13 = pheapAddr;
          }
          p_pObject -= 2;
          --v44;
        }
        while ( v44 );
        if ( v15 >= v13->Policy.Capacity >> 1 )
          goto LABEL_37;
        Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v13,
          v13,
          v15);
        goto LABEL_36;
      }
      if ( v15 >= pheapAddr->Policy.Capacity )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          pheapAddr,
          pheapAddr,
          v15 + (v15 >> 2));
LABEL_36:
        v13 = pheapAddr;
      }
LABEL_37:
      v13->Size = v15;
      v16 = &v13->Data[v15 - 1].Char.pObject;
      if ( v16 )
      {
        if ( v12 )
          ++v12->RefCount;
        *v16 = v12;
        v16[1] = v4;
      }
      if ( v12 )
        Scaleform::RefCountNTSImpl::Release(v12);
      if ( !v12->pParent )
      {
        Scaleform::GFx::InteractiveObject::AddToPlayList(v12);
        Flags = v12->Flags;
        LOBYTE(Flags) = (Flags & 0x200000) != 0 && (Flags >>= 22, (Flags & 1) == 0);
        v18 = v12->CheckAdvanceStatus(v12, Flags);
        if ( v18 == -1 )
        {
          v12->Flags |= (unsigned int)&loc_400000;
        }
        else if ( v18 == 1 )
        {
          Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v12);
        }
      }
      RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v51);
      v19 = *(_DWORD *)(*(_DWORD *)(((unsigned int)v41 & 0xFFFFF000) + 0x10)
                      + 4 * ((int)((int)&v41[-1] - ((unsigned int)v41 & 0xFFFFF000)) / 28)
                      + 20);
      v20 = *(_DWORD *)(v19 + 144);
      v21 = v19 + 144;
      if ( v20 )
      {
        if ( (v20 & 1) != 0 )
          v20 = *(_DWORD *)((v20 & 0xFFFFFFFE) + 4);
        else
          v20 = (*(_DWORD *)(v21 + 4) != 0) + 1;
      }
      Scaleform::Render::TreeContainer::Insert(v41, v20, RenderNode);
      Scaleform::RefCountNTSImpl::Release(v51);
      pClassName = v47;
      v1 = this;
LABEL_60:
      Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
        *((Scaleform::GFx::MovieDefImpl **)v1[-1].pClassName + 25),
        (Scaleform::GFx::ResourceBinding *)&v75,
        *(Scaleform::GFx::ResourceId *)(v4 + 68));
      if ( v75 )
      {
        Scaleform::Render::Cxform::Cxform(&v57);
        v67 = 0.0;
        v23 = *(_DWORD *)(v4 + 68);
        v24 = *(float *)v4;
        v71 = 0;
        v66 = 0;
        v70 = 0;
        v25 = *(_BYTE *)(v4 + 76);
        qmemcpy(&v57, (const void *)(v4 + 32), sizeof(v57));
        v58 = v24;
        v59 = *(float *)(v4 + 4);
        v60 = *(float *)(v4 + 8);
        v61 = *(float *)(v4 + 12);
        v62 = *(float *)(v4 + 16);
        v63 = *(float *)(v4 + 20);
        v26 = *(unsigned __int16 *)(v4 + 72);
        v64 = *(float *)(v4 + 24);
        v65 = *(float *)(v4 + 28);
        v73 = v25;
        v69 = v23;
        v68 = v26;
        v27 = this[-1].pClassName;
        v72 = 143;
        v28 = *(_DWORD *)(*((_DWORD *)v27 + 4) + 432);
        v52 = (Scaleform::GFx::ASStringNode *)(v28 + 32);
        ++*(_DWORD *)(v28 + 44);
        v29 = ((int (__thiscall *)(Scaleform::RefCountNTSImpl *, Scaleform::Render::Cxform *, Scaleform::GFx::ASStringNode **, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD))v48->__vftable[119].~Scaleform::RefCountNTSImpl)(
                v48,
                &v57,
                &v52,
                0,
                0,
                0,
                4,
                0,
                0);
        v30 = v52;
        --v52->RefCount;
        if ( !v30->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v30);
        if ( v29 && *(_DWORD *)(v4 + 64) )
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v29 + 216))(v29, *(_DWORD *)(v4 + 64));
        if ( (v47[62] & 1) != 0 )
        {
          v31 = v48->__vftable[18].~Scaleform::RefCountNTSImpl;
          HIWORD(v48[7].RefCount) |= 1u;
          v31(v48);
        }
        if ( v66 )
          Scaleform::RefCountImpl::Release(v66);
        v1 = this;
        pClassName = v47;
      }
      if ( buttonState == 3 )
        v48[4].__vftable = (Scaleform::RefCountNTSImpl_vtbl *)pClassName;
      v32 = v41;
      if ( v55 == buttonState && !v41->pParent )
      {
        v33 = (*(int (__thiscall **)(char *))(*(_DWORD *)pClassName + 268))(pClassName);
        v34 = *(_DWORD *)(*(_DWORD *)((v33 & 0xFFFFF000) + 0x10) + 4 * ((int)(v33 - (v33 & 0xFFFFF000) - 28) / 28) + 20);
        v35 = *(_DWORD *)(v34 + 144);
        v36 = v34 + 144;
        if ( v35 )
        {
          if ( (v35 & 1) != 0 )
            v35 = *(_DWORD *)((v35 & 0xFFFFFFFE) + 4);
          else
            v35 = (*(_DWORD *)(v36 + 4) != 0) + 1;
        }
        Scaleform::Render::TreeContainer::Insert((Scaleform::Render::TreeContainer *)v33, v35, v41);
        pClassName = v47;
        v1 = this;
        v32 = v41;
      }
      if ( v48 )
      {
        Scaleform::RefCountNTSImpl::Release(v48);
        v32 = v41;
      }
      if ( v32 )
      {
        if ( v32->RefCount-- == 1 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v32);
      }
      v5 = v39;
LABEL_86:
      v5 *= 2;
      v39 = v5;
    }
    while ( (v5 & 0xF) != 0 );
    v49 += 96;
    if ( --v53 )
    {
      v3 = v54;
      continue;
    }
    break;
  }
}
