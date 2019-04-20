FROM php:apache
COPY app/ /var/www/html
COPY docker-php.conf /etc/apache2/conf-available/
RUN chmod -R 777 /var/www/html/uploads/
EXPOSE 80