void __thiscall boost::weak_ptr<void>::~weak_ptr<void>(boost::weak_ptr<void> *this)
{
  boost::detail::weak_count *p_pn; // [esp+4h] [ebp-8h]
  boost::detail::sp_counted_base *pi; // [esp+8h] [ebp-4h]

  p_pn = &this->pn;
  if ( this->pn.pi_ )
  {
    pi = p_pn->pi_;
    if ( !_InterlockedDecrement(&p_pn->pi_->weak_count_) )
      ((void (__thiscall *)(boost::detail::sp_counted_base *, boost::weak_ptr<void> *))pi->destroy)(pi, this);
  }
}
