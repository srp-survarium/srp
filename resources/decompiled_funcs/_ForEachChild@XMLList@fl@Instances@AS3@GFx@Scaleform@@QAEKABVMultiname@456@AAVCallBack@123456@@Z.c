unsigned int __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::ForEachChild(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        const Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Instances::fl::XMLList::CallBack *cb)
{
  const Scaleform::GFx::AS3::Multiname *v3; // ebp
  unsigned int v4; // esi
  Scaleform::GFx::ASStringNode *VStr; // edi
  unsigned int v6; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // esi
  unsigned int v8; // ebx
  int v9; // esi
  int Namespace; // edi
  int v11; // eax
  Scaleform::GFx::AS3::GASRefCountBase *v12; // edi
  Scaleform::GFx::AS3::RefCountCollector<328> *pRCC; // eax
  _DWORD *v14; // edi
  int v15; // ebp
  int v16; // ebx
  int v17; // eax
  unsigned int result; // [esp+8h] [ebp-24h]
  unsigned int i; // [esp+Ch] [ebp-20h]
  unsigned int k; // [esp+10h] [ebp-1Ch]
  Scaleform::GFx::ASString name; // [esp+14h] [ebp-18h]
  Scaleform::GFx::AS3::Instances::fl::XMLList *v24; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS3::Instances::fl::XML *el; // [esp+1Ch] [ebp-10h]
  Scaleform::GFx::AS3::RefCountCollector<328> *v26; // [esp+20h] [ebp-Ch]
  unsigned int children_size; // [esp+24h] [ebp-8h]
  unsigned int size; // [esp+28h] [ebp-4h]

  v3 = prop_name;
  v4 = 0;
  v24 = this;
  result = 0;
  if ( (prop_name->Name.Flags & 0x1F) != 0xA )
    return 0;
  VStr = prop_name->Name.value.VS._1.VStr;
  ++VStr->RefCount;
  v6 = 0;
  name.pNode = VStr;
  size = this->List.Data.Size;
  i = 0;
  if ( size )
  {
    while ( 1 )
    {
      pObject = this->List.Data.Data[v6].pObject;
      el = pObject;
      if ( pObject->GetKind(pObject) == kElement )
      {
        v8 = 0;
        children_size = (unsigned int)pObject[1].Text.pNode;
        k = 0;
        if ( children_size )
        {
          while ( 1 )
          {
            v9 = *((_DWORD *)&pObject[1].pUserDataHolder->pMovieView + v8);
            if ( *(Scaleform::GFx::ASStringNode **)(*(int (__thiscall **)(int))(*(_DWORD *)v9 + 108))(v9) == VStr
              || Scaleform::GFx::AS3::Multiname::IsAnyType(v3) )
            {
              if ( Scaleform::GFx::AS3::Multiname::IsQName(v3) )
              {
                if ( Scaleform::GFx::AS3::Multiname::IsAnyNamespace(v3)
                  || (Namespace = Scaleform::GFx::AS3::Multiname::GetNamespace((Scaleform::GFx::AS3::SoundObject *)v3),
                      v11 = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 112))(v9),
                      *(_DWORD *)(Namespace + 28) == *(_DWORD *)(v11 + 28))
                  && ((*(_BYTE *)(Namespace + 20) ^ *(_BYTE *)(v11 + 20)) & 0xF) == 0 )
                {
                  cb->Call(cb, i, v8);
                  ++result;
                }
              }
              else
              {
                v12 = v3->Obj.pObject;
                pRCC = v12[1]._pRCC;
                v14 = &v12[1].__vftable;
                v15 = 0;
                v26 = pRCC;
                if ( pRCC )
                {
                  while ( 1 )
                  {
                    v16 = *(_DWORD *)(*v14 + 4 * v15);
                    v17 = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 112))(v9);
                    if ( *(_DWORD *)(v16 + 28) == *(_DWORD *)(v17 + 28)
                      && ((*(_BYTE *)(v16 + 20) ^ *(_BYTE *)(v17 + 20)) & 0xF) == 0 )
                    {
                      break;
                    }
                    if ( ++v15 >= (unsigned int)v26 )
                      goto LABEL_23;
                  }
                  cb->Call(cb, i, k);
                  ++result;
LABEL_23:
                  v8 = k;
                }
                v3 = prop_name;
              }
            }
            VStr = name.pNode;
            k = ++v8;
            if ( v8 >= children_size )
              break;
            pObject = el;
          }
        }
      }
      v6 = i + 1;
      i = v6;
      if ( v6 >= size )
        break;
      this = v24;
    }
    v4 = result;
  }
  if ( VStr->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
  return v4;
}
