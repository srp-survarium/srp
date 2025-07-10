void __usercall survarium::flash_text_manager::tick(survarium::flash_text_manager *this@<ecx>, int a2@<esi>)
{
  if ( *(_BYTE *)(a2 + 4) )
  {
    Scaleform::GFx::DrawTextManager::Capture(*(Scaleform::GFx::DrawTextManager **)a2, 1);
    *(_BYTE *)(a2 + 4) = 0;
  }
}
