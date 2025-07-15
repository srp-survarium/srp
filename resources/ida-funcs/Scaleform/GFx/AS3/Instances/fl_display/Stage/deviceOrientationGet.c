void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::deviceOrientationGet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::VM *pVM; // eax
  char *v3; // edx
  Scaleform::GFx::ASStringNode *ConstStringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v6; // zf

  pVM = this->pTraits.pObject->pVM;
  switch ( *((_DWORD *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 4120) )
  {
    case 0:
      v3 = "default";
      break;
    case 1:
      v3 = "rotatedLeft";
      break;
    case 2:
      v3 = "rotatedRight";
      break;
    case 3:
      v3 = "upsideDown";
      break;
    default:
      v3 = "unknown";
      break;
  }
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      pVM->StringManagerRef->pStringManager,
                      v3,
                      strlen(v3),
                      0);
  ConstStringNode->RefCount += 2;
  pNode = result->pNode;
  v6 = result->pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = ConstStringNode;
  v6 = ConstStringNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
}
