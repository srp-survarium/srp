void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::fscommand(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASStringNode *argc,
        const Scaleform::GFx::AS3::Value *const argv)
{
  int v4; // ebp
  char v5; // dl
  unsigned int v6; // esi
  const Scaleform::GFx::AS3::Value *v7; // eax
  Scaleform::GFx::ASStringNode *VStr; // edi
  Scaleform::GFx::ASStringNode *v9; // ecx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // eax
  Scaleform::GFx::ASStringNode *pNode; // esi
  bool v12; // zf
  void (__thiscall *proot)(Scaleform::GFx::AS3::VM *); // [esp+4h] [ebp-4h]

  v4 = *((_DWORD *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 119);
  v5 = 0;
  proot = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  if ( v4 )
  {
    v6 = (unsigned int)argc;
    if ( argc )
    {
      v7 = argv;
      VStr = argv->value.VS._1.VStr;
      ++VStr->RefCount;
      if ( v6 <= 1 )
      {
        StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
        v9 = argc;
      }
      else
      {
        v9 = v7[1].value.VS._1.VStr;
        ++v9->RefCount;
        v5 = 1;
        argc = v9;
        StringManagerRef = (Scaleform::GFx::AS3::StringManager *)&argc;
      }
      pNode = StringManagerRef->Builtins[0].pNode;
      ++StringManagerRef->Builtins[0].pNode->RefCount;
      if ( (v5 & 1) != 0 )
      {
        v12 = v9->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      }
      (*(void (__thiscall **)(int, void (__thiscall *)(Scaleform::GFx::AS3::VM *), const char *, const char *))(*(_DWORD *)v4 + 4))(
        v4,
        proot,
        VStr->pData,
        pNode->pData);
      v12 = pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v12 = VStr->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
    }
  }
}
