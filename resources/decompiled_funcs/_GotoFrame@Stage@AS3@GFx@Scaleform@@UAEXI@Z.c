void __thiscall Scaleform::GFx::AS3::Stage::GotoFrame(Scaleform::GFx::AS3::Stage *this, unsigned int targetFrameNumber)
{
  Scaleform::GFx::DisplayObjContainer *pObject; // ecx

  pObject = this->pRoot.pObject;
  if ( pObject )
    pObject->GotoFrame(pObject, targetFrameNumber);
}
