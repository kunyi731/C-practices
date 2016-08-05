typedef struct 
{
  int    m_id;
  int    m_purchaseDate;  // year purchased
  double m_cost;
} Asset;

typedef struct
{
  Asset  base;
  double m_lastPrice;
  int    m_shares;
  char   m_symbol[12];
} Stock;

typedef struct 
{
  Asset  base;
  double m_faceValue;
  double m_interestRate;
  int    m_dateOfMaturity;
} Bond;

typedef struct 
{
  Asset base;
  double m_assessment;
} Property;

typedef struct
{
  Property base;
  double m_acres;
} Land;

typedef struct Building 
{
  Property base;
  int m_stories;
};

void Asset_ctor(Asset* self, int id, int date, double cost)
{
    self->m_id = id;
    self->m_purchaseDate = date;
    self->m_cost = cost;
}

void Stock_ctor(Stock* self, int id, int date, double cost,
                const char* sym, double price, int shares)
{
    Asset_ctor(&self->base, id, date, cost);
    strcpy(self->m_symbol, sym);
    self->m_lastPrice  = price;
    self->m_shares     = shares;
}

void Bond_ctor(Bond* self, int id, int date, double cost,
               double face, double interest, int maturity)
{
    Asset_ctor(&self->base, id, date, cost);
    self->m_faceValue = face;
    self->m_interestRate = interest;
    self->m_dateOfMaturity = maturity;
}

void Asset_print(Asset* self)
{
    printf("ID: %d\nPurchase Year: %d\nInitial Cost: %lf\n",
           self->m_id, self->m_purchaseDate, self->m_cost);
}
 
void Stock_print(Stock* self)
{
    Asset_print(&self->base);
    printf("Stock!i\n");
}

void Bond_print(Bond* self)
{
    Asset_print(&self->base);
    printf("Bond!!\n");
}

int main()
{
    Stock    microsoft;
    Bond     citicorp;
 
    Stock_ctor(&microsoft, 100, 1994, 8000, "MSFT", 56, 200);
    Bond_ctor(&citicorp, 200, 1980, 9400, 10000, 6.0, 2010);

    Asset_print(&microsoft);

    printf("\n------------\n");
    Stock_print(&microsoft);
    Bond_print(&citicorp);

}


