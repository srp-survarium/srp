unsigned int __userpurge Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstance@<eax>(
        Scaleform::GFx::AS3::AvmDisplayObj *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        bool execute)
{
  if ( this->pAS3RawPtr
    || this->pAS3CollectiblePtr.pObject
    || !Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(this, a2, a3) )
  {
    return 0;
  }
  else
  {
    return Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(this, execute);
  }
}
