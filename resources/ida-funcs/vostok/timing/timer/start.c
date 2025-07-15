void __usercall vostok::timing::timer::start(vostok::timing::timer *this@<ecx>, LARGE_INTEGER *a2@<esi>)
{
  LARGE_INTEGER QPC; // rax

  QPC = vostok::timing::get_QPC();
  a2->LowPart = 0;
  a2->HighPart = 0;
  a2[1] = QPC;
}
