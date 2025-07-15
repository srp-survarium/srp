void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3toXMLString(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *v2; // edi
  Scaleform::GFx::AS3::VM *pVM; // edx
  const Scaleform::MemoryHeap *MHeap; // eax
  unsigned int v5; // ebx
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // ebp
  unsigned int v8; // eax
  int v9; // ecx
  int v10; // eax
  _DWORD *v11; // edi
  unsigned int v12; // ebx
  unsigned int j; // esi
  int v14; // eax
  int v15; // eax
  _DWORD *v16; // edi
  unsigned int v17; // ebx
  unsigned int k; // esi
  int v19; // eax
  unsigned int m; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *v21; // ecx
  char *pData; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v25; // zf
  Scaleform::GFx::AS3::Instances::fl::XML *xml; // [esp+Ch] [ebp-40h]
  Scaleform::GFx::AS3::Instances::fl::XML *xmla; // [esp+Ch] [ebp-40h]
  unsigned int i; // [esp+10h] [ebp-3Ch]
  unsigned int size; // [esp+14h] [ebp-38h]
  Scaleform::GFx::AS3::VM *vm; // [esp+1Ch] [ebp-30h]
  unsigned int RefCount; // [esp+20h] [ebp-2Ch]
  Scaleform::GFx::AS3::NamespaceArray na; // [esp+24h] [ebp-28h] BYREF
  Scaleform::StringBuffer buf; // [esp+34h] [ebp-18h] BYREF

  v2 = this;
  pVM = this->pTraits.pObject->pVM;
  MHeap = pVM->MHeap;
  v5 = this->List.Data.Size;
  vm = pVM;
  size = v5;
  memset((void *)&na, 0, 12);
  na.Namespaces.Data.pHeap = MHeap;
  if ( v5 )
  {
    pObject = this->TargetObject.pObject;
    v7 = pVM->PublicNamespace.pObject;
    xml = (Scaleform::GFx::AS3::Instances::fl::XML *)pObject;
    if ( pObject )
    {
      while ( !Scaleform::GFx::AS3::IsXMLObject(pObject) )
      {
        if ( Scaleform::GFx::AS3::IsXMLListObject(pObject) )
        {
          v8 = 0;
          RefCount = pObject[1].RefCount;
          i = 0;
          if ( RefCount )
          {
            do
            {
              v9 = *((_DWORD *)&pObject[1].pPrev->Scaleform::GFx::AS3::Instance::Scaleform::GFx::AS3::Object::Scaleform::GFx::AS3::GASRefCountBase::Scaleform::GFx::AS3::RefCountBaseGC<328>::$6995B294EB399C8E7199C0A182ACF77B::__vftable
                   + v8);
              v10 = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 68))(v9);
              v11 = (_DWORD *)v10;
              if ( v10 )
              {
                v12 = *(_DWORD *)(v10 + 4);
                for ( j = 0; j < v12; ++j )
                {
                  v14 = *(_DWORD *)(*v11 + 4 * j);
                  if ( *(Scaleform::GFx::ASStringNode **)(v14 + 28) != v7->Uri.pNode
                    || ((*((_BYTE *)v7 + 20) ^ *(_BYTE *)(v14 + 20)) & 0xF) != 0 )
                  {
                    Scaleform::GFx::AS3::NamespaceArray::Add(
                      &na,
                      (Scaleform::GFx::AS3::Instances::fl::Namespace *)v14,
                      1);
                  }
                }
                pObject = xml;
              }
              v8 = i + 1;
              i = v8;
            }
            while ( v8 < RefCount );
            v5 = size;
            v2 = this;
          }
          xml = (Scaleform::GFx::AS3::Instances::fl::XML *)pObject[1].__vftable;
          pObject = xml;
        }
        if ( !pObject )
          goto LABEL_27;
      }
      xmla = (Scaleform::GFx::AS3::Instances::fl::XML *)pObject;
      do
      {
        v15 = (int)xmla->GetInScopeNamespaces(xmla);
        v16 = (_DWORD *)v15;
        if ( v15 )
        {
          v17 = *(_DWORD *)(v15 + 4);
          for ( k = 0; k < v17; ++k )
          {
            v19 = *(_DWORD *)(*v16 + 4 * k);
            if ( *(Scaleform::GFx::ASStringNode **)(v19 + 28) != v7->Uri.pNode
              || ((*((_BYTE *)v7 + 20) ^ *(_BYTE *)(v19 + 20)) & 0xF) != 0 )
            {
              Scaleform::GFx::AS3::NamespaceArray::Add(&na, (Scaleform::GFx::AS3::Instances::fl::Namespace *)v19, 1);
            }
          }
        }
        xmla = xmla->Parent.pObject;
      }
      while ( xmla );
      v5 = size;
      v2 = this;
    }
  }
LABEL_27:
  Scaleform::StringBuffer::StringBuffer(&buf, vm->MHeap);
  for ( m = 0; m < v5; ++m )
  {
    if ( m )
      Scaleform::StringBuffer::AppendChar(&buf, 0xAu);
    v21 = v2->List.Data.Data[m].pObject;
    v21->ToXMLString(v21, &buf, 0, 0, &na);
  }
  pData = buf.pData;
  if ( !buf.pData )
    pData = (char *)&::buf;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(vm->StringManagerRef->pStringManager, pData, buf.Size);
  StringNode->RefCount += 2;
  pNode = result->pNode;
  v25 = result->pNode->RefCount-- == 1;
  if ( v25 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = StringNode;
  v25 = StringNode->RefCount-- == 1;
  if ( v25 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buf);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)na.Namespaces.Data.Data,
    na.Namespaces.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, na.Namespaces.Data.Data);
}


Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3toXMLString(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax

  p_EmptyStringNode = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  result->pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  Scaleform::GFx::AS3::Instances::fl::XMLList::AS3toXMLString(this, result);
  return result;
}
