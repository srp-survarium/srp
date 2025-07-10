void __userpurge Scaleform::GFx::AS3::FrameCounter::AdvanceFrame(
        Scaleform::GFx::AS3::FrameCounter *this@<ecx>,
        int a2@<ebp>,
        bool nextFrame,
        float framePos)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // esi
  Scaleform::GFx::AS3::ASVM *v6; // eax

  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  if ( nextFrame )
  {
    if ( pObject->ASFramesToExecute )
    {
      Scaleform::GFx::AS3::VM::ExecuteCode(pObject->pAVM.pObject, pObject->ASFramesToExecute);
      v6 = pObject->pAVM.pObject;
      if ( v6->HandleException )
        v6->HandleException = 0;
      pObject->ASFramesToExecute = 0;
    }
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, a2, AL_Highest);
    Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, a2, AL_High);
    Scaleform::GFx::AS3::FrameCounter::QueueFrameActions(this);
    Scaleform::GFx::AS3::MovieRoot::RequeueActionQueue(pObject, AL_Count_, AL_Frame);
  }
}
