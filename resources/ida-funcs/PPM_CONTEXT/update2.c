void __usercall PPM_CONTEXT::update2(
        PPM_CONTEXT *this@<ecx>,
        ppmd_compressor_impl *impl@<edi>,
        PPM_CONTEXT::STATE *p@<eax>)
{
  int InitRL; // eax

  impl->FoundState = p;
  p->Freq += 4;
  this->SummFreq += 4;
  if ( p->Freq > 0x7Cu )
    PPM_CONTEXT::rescale(this, &this->NumStats, impl);
  InitRL = impl->InitRL;
  ++impl->EscCount;
  impl->RunLength = InitRL;
}
