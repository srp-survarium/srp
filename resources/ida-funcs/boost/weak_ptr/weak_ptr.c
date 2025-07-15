void __userpurge boost::weak_ptr<void>::weak_ptr<void>(
        boost::weak_ptr<void> *this@<ecx>,
        void **a2@<eax>,
        const boost::shared_ptr<void> *r,
        boost::detail::sp_empty __formal)
{
  boost::detail::sp_counted_base *pi; // ecx

  *a2 = this->px;
  pi = this->pn.pi_;
  a2[1] = pi;
  if ( pi )
    _InterlockedExchangeAdd(&pi->weak_count_, 1u);
}


void __usercall boost::weak_ptr<void>::weak_ptr<void>(boost::weak_ptr<void> *this@<ecx>, void **a2@<eax>)
{
  boost::detail::sp_counted_base *pi; // ecx

  *a2 = this->px;
  pi = this->pn.pi_;
  a2[1] = pi;
  if ( pi )
    _InterlockedExchangeAdd(&pi->weak_count_, 1u);
}
