void __usercall survarium::weapon::initialize(survarium::weapon *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  survarium::weapon_core::initialize(this, a2, a3, (int)this);
  this->m_is_scope_aimed = 0;
}


void __usercall survarium::weapon::initialize(int a1@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  survarium::weapon::initialize((survarium::weapon *)(a1 - 16), a2, a3);
}
