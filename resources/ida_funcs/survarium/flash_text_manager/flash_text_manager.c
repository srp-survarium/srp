void __usercall survarium::flash_text_manager::flash_text_manager(
        survarium::flash_text_manager *this@<esi>,
        Scaleform::GFx::Loader *loader@<eax>)
{
  Scaleform::MemoryHeap *v2; // ecx
  Scaleform::GFx::DrawTextManager *v4; // eax
  Scaleform::GFx::DrawTextManager *v5; // eax
  Scaleform::GFx::State *v6; // edi
  const Scaleform::GFx::DrawTextManager::TextParams *DefaultTextParams; // eax
  Scaleform::GFx::DrawTextManager *text_manager_impl; // ecx
  void *v9; // edi
  Scaleform::GFx::DrawTextManager::TextParams defParams; // [esp+18h] [ebp-1Ch] BYREF

  v2 = Scaleform::Memory::pGlobalHeap;
  this->need_capture = 0;
  v4 = (Scaleform::GFx::DrawTextManager *)v2->Alloc(v2, 20u, 0);
  if ( v4 )
    Scaleform::GFx::DrawTextManager::DrawTextManager(v4, loader);
  else
    v5 = 0;
  this->text_manager_impl = v5;
  v6 = loader->GetStateAddRef(loader, 19);
  this->text_manager_impl->SetState(&this->text_manager_impl->Scaleform::GFx::StateBag, State_FontProvider, v6);
  if ( v6 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v6);
  DefaultTextParams = Scaleform::GFx::DrawTextManager::GetDefaultTextParams(this->text_manager_impl);
  Scaleform::GFx::DrawTextManager::TextParams::TextParams(&defParams, DefaultTextParams);
  defParams.TextColor.Raw = -16711936;
  Scaleform::String::operator=(&defParams.FontName, "Arial");
  text_manager_impl = this->text_manager_impl;
  defParams.FontSize = 16.0;
  Scaleform::GFx::DrawTextManager::SetDefaultTextParams(text_manager_impl, &defParams);
  v9 = (void *)(defParams.FontName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((defParams.FontName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
}
