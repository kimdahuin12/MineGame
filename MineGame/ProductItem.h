#pragma once
class ProductItem
{
private:
	char* itemName;
	unsigned int itemPrice;
	static int itemCount;
public:
	ProductItem();
	~ProductItem();
};

