int __thiscall Scaleform::GFx::AS3::Stage::GetCurrentFrame(Scaleform::GFx::AS3::Stage *this)
{
  Scaleform::GFx::DisplayObjContainer *pObject; // ecx

  pObject = this->pRoot.pObject;
  if ( pObject )
    return pObject->GetCurrentFrame(pObject);
  else
    return 0;
}
