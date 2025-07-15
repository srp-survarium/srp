void __usercall Scaleform::GFx::AS3::MovieRoot::DoActions(Scaleform::GFx::AS3::MovieRoot *this@<ecx>, int a2@<ebp>)
{
  unsigned int ASFramesToExecute; // eax
  Scaleform::GFx::AS3::ASVM *pObject; // eax
  Scaleform::GFx::AS3::MovieRoot::ActionLevel i; // edi
  Scaleform::GFx::AS3::ASVM *v6; // esi

  ASFramesToExecute = this->ASFramesToExecute;
  if ( ASFramesToExecute )
  {
    Scaleform::GFx::AS3::VM::ExecuteCode(this->pAVM.pObject, ASFramesToExecute);
    pObject = this->pAVM.pObject;
    if ( pObject->HandleException )
      pObject->HandleException = 0;
    this->ASFramesToExecute = 0;
  }
  for ( i = AL_Highest; (unsigned int)i < AL_Count_; ++i )
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(this, a2, i);
  Scaleform::GFx::AS3::MovieRoot::CheckSocketMessages(this);
  v6 = this->pAVM.pObject;
  if ( v6->HandleException )
    v6->HandleException = 0;
}
