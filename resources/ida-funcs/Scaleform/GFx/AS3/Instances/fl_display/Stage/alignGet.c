void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::alignGet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        Scaleform::GFx::ASString *result)
{
  void (__thiscall *v3)(Scaleform::GFx::AS3::VM *); // ecx
  char *v4; // edx
  Scaleform::GFx::ASStringNode *v5; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+8h] [ebp-4h] BYREF

  v3 = this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM;
  switch ( (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v3 + 64))(v3) )
  {
    case 1:
      v4 = "T";
      break;
    case 2:
      v4 = "B";
      break;
    case 3:
      v4 = "L";
      break;
    case 4:
      v4 = "R";
      break;
    case 5:
      v4 = "LT";
      break;
    case 6:
      v4 = "TR";
      break;
    case 7:
      v4 = "LB";
      break;
    case 8:
      v4 = "RB";
      break;
    default:
      v4 = (char *)uri;
      break;
  }
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                      v4,
                      strlen(v4),
                      0);
  ++ConstStringNode->RefCount;
  Scaleform::GFx::ASString::Append(result, (Scaleform::GFx::ASStringNode *)&ConstStringNode);
  v5 = ConstStringNode;
  --ConstStringNode->RefCount;
  if ( !v5->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
}
