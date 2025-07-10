unsigned int __thiscall Scaleform::Render::HAL::DrawableCommandGetFlags(
        Scaleform::Render::HAL *this,
        const Scaleform::Render::DICommand *pcmd)
{
  unsigned int result; // eax

  if ( !pcmd )
    return 0;
  switch ( pcmd->GetType(pcmd) )
  {
    case DICommandType_Map:
    case DICommandType_Unmap:
    case DICommandType_CreateTexture:
      result = 10;
      break;
    case DICommandType_Clear:
    case DICommandType_ApplyFilter:
    case DICommandType_Draw:
    case DICommandType_CopyChannel:
    case DICommandType_CopyPixels:
    case DICommandType_ColorTransform:
    case DICommandType_Compare:
    case DICommandType_FillRect:
    case DICommandType_Merge:
    case DICommandType_PaletteMap:
    case DICommandType_Scroll:
      result = 6;
      break;
    case DICommandType_Threshold:
      result = 2;
      break;
    default:
      return 0;
  }
  return result;
}
