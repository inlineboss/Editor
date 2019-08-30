#ifndef FUNCTIONAL_INTERFACE_H_
#define FUNCTIONAL_INTERFACE_H_

/**
 * \brief Интерфейс отрисовки
 */
class Draw_interface{
public:
	/**
	 * \brief Метод отрисовки объекта
	 */
	virtual void draw () = 0;
	virtual ~Draw_interface(){};
};

/**
 * \brief Интерфейс удаления
 */
class Remove_interface{
public:
	/**
	 * \brief Метод удаления объекта
	 */
	virtual void remove () = 0;
	virtual ~Remove_interface(){};
};

/**
 * \brief Интерфейс получения имени
 */
class Name_interface{
public:
	virtual std::string is_name() = 0;
	virtual ~Name_interface(){};
};

#endif /* FUNCTIONAL_INTERFACE_H_ */
