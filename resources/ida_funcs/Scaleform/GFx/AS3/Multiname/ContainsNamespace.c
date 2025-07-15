char __thiscall Scaleform::GFx::AS3::Multiname::ContainsNamespace(
        Scaleform::GFx::AS3::Multiname *this,
        const Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // eax

  if ( (this->Kind & 3) == 2 )
    return Scaleform::GFx::AS3::NamespaceSet::Contains((Scaleform::GFx::AS3::NamespaceSet *)this->Obj.pObject, ns);
  pObject = this->Obj.pObject;
  return pObject[1].pNext == (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)ns->Uri.pNode
      && ((*((_BYTE *)ns + 20) ^ LOBYTE(pObject[1].__vftable)) & 0xF) == 0;
}
